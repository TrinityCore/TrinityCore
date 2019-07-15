-- 
UPDATE `points_of_interest` SET `ID` = `ID` + 10000;
UPDATE `gossip_menu_option_action` SET `ActionPoiId` = `ActionPoiId` + 10000 WHERE `ActionPoiId` != 0;

DELETE FROM `points_of_interest` WHERE `ID` IN (5047, 4492, 4473, 4472, 4468, 4469, 4467, 4474, 4481, 4489, 4487, 4488, 4482, 4490, 4479, 4470, 4483, 4484, 4497, 4477, 4480, 4491, 4478, 4466, 4495, 4494, 4493, 4471, 4475, 4496, 4476, 4485, 4486, 2731, 2729, 2727, 2734, 2730, 2733, 2732, 2726, 2728, 2928, 93, 108, 68, 94, 2424, 91, 5212, 5214, 2518, 5216, 5213, 5215, 532, 2420, 2110, 2421, 72, 1467, 2419, 529, 2415, 47, 2416, 527, 87, 67, 2766, 70, 75, 1986, 69, 73, 71, 74, 2417, 2202, 2714, 2887, 2800, 2886, 2839, 2844, 2796, 2956, 2858, 2798, 2807, 2815, 2857, 2811, 2802, 2803, 2797, 2812, 2856, 2810, 2820, 2808, 2801, 2805, 2813, 2814, 2806, 2804, 2795, 2845, 2881, 2843, 2842, 2840, 2837, 2838, 2882, 2835, 2833, 2827, 2832, 2831, 2830, 2829, 2828, 2826, 2825, 2824, 2823, 2822, 2821, 2819, 2794, 2793, 2792);
INSERT INTO `points_of_interest` (`ID`, `PositionX`, `PositionY`, `Icon`, `Flags`, `Importance`, `Name`, `VerifiedBuild`) VALUES
(5047, 3744.84, -4054.93, 7, 99, 0, 'Item Upgrade', 27602),
(4492, 3745.7, -3972.66, 7, 99, 0, 'Trade Goods', 27602),
(4473, 3632.13, -3907.58, 7, 99, 0, 'General Goods', 27602),
(4472, 3561.27, -3932.85, 7, 99, 0, 'Reputation Vendors', 27602),
(4468, 3604.85, -3997.28, 7, 99, 0, 'Auction House', 27602),
(4469, 3623.07, -3967.33, 7, 99, 0, 'Apexis Crystal Vendors', 27602),
(4467, 3744.84, -4054.93, 7, 99, 0, 'Ethereal Services', 27602),
(4474, 3606.91, -3855.3, 7, 99, 0, 'Stable Master', 27602),
(4481, 3712.3, -3947.85, 7, 99, 0, 'Mining Trainer', 27602),
(4489, 3735.22, -3979.09, 7, 99, 0, 'Tailoring Trainer', 27602),
(4487, 3713.95, -3981.62, 7, 99, 0, 'Skinning Trainer', 27602),
(4488, 3713.95, -3981.62, 7, 99, 0, 'Leatherworking Trainer', 27602),
(4482, 3750.38, -3927.39, 7, 99, 0, 'Jewelcrafting Trainer', 27602),
(4490, 3751.35, -4057.59, 7, 99, 0, 'Inscription Trainer', 27602),
(4479, 3586.81, -3881.44, 7, 99, 0, 'Herbalism Trainer', 27602),
(4470, 3551.1, -4006.96, 7, 99, 0, 'Fishing Trainer', 27602),
(4483, 3768.32, -3948, 7, 99, 0, 'First Aid Trainer', 27602),
(4484, 3721.87, -3953, 7, 99, 0, 'Engineering Trainer', 27602),
(4497, 3611.07, -4012.55, 7, 99, 0, 'Enchanting Trainer', 27602),
(4477, 3556.81, -3867.84, 7, 99, 0, 'Cooking Trainer', 27602),
(4480, 3689.56, -3962.55, 7, 99, 0, 'Blacksmithing Trainer', 27602),
(4491, 3753.11, -3961.85, 7, 99, 0, 'Archaeology Trainer', 27602),
(4478, 3589.52, -3877.18, 7, 99, 0, 'Alchemy Trainer', 27602),
(4466, 3555.23, -3872.99, 7, 99, 0, 'Battle Pet Trainer', 27602),
(4495, 3729.44, -4042.35, 7, 99, 0, 'Portal to Stormwind', 27602),
(4494, 3672.25, -3975.87, 7, 99, 0, 'Portal to Ironforge', 27602),
(4493, 3614.41, -4055.75, 7, 99, 0, 'Portal to Darnassus', 27602),
(4471, 3594.41, -3920.9, 7, 99, 0, 'Mailbox', 27602),
(4475, 3580.43, -3869.11, 7, 99, 0, 'Mailbox', 27602),
(4496, 3710.9, -3978.03, 7, 99, 0, 'Mailbox', 27602),
(4476, 3557.32, -3869.9, 7, 99, 0, 'Hero\'s Rest Inn', 27602),
(4485, 3683.11, -3837.56, 7, 99, 0, 'Flightmaster', 27602),
(4486, 3686, -3999.8, 7, 99, 0, 'Bronzebeard\'s Vault', 27602),
(2731, 211.3802, 907.5104, 7, 99, 0, 'Tina Mudclaw\'s House', 27377),
(2729, 95.37327, 1320.281, 7, 99, 0, 'Sho\'s House', 27377),
(2727, -306.7552, 1476.707, 7, 99, 0, 'Old Hillpaw\'s House', 27377),
(2734, -281.1406, 575.7327, 7, 99, 0, 'Jogu\'s House', 27377),
(2730, 205.3507, 928.7518, 7, 99, 0, 'Haohan Mudclaw\'s House', 27377),
(2733, 307.0573, 1043.502, 7, 99, 0, 'Fish Fellreed\'s House', 27377),
(2732, 210.441, 784.0018, 7, 99, 0, 'Farmer Fung\'s House', 27377),
(2726, -429.217, 1451.833, 7, 99, 0, 'Ella\'s House', 27377),
(2728, -125.8611, 1348.696, 7, 99, 0, 'Chee Chee\'s House', 27377),
(2928, 900.6198, 4631.574, 189, 64, 0, 'Gokk\'lok Shallows', 27377),
(93, -8365.68, 631.149, 7, 99, 0, 'Stormwind Engineering', 27843),
(108, -8854.98, 800.08, 7, 99, 0, 'Stormwind Enchanting', 27843),
(68, -8634.73, 415.613, 7, 99, 0, 'Stormwind Inn', 27843),
(94, -8424.52, 616.797, 7, 99, 0, 'Stormwind Blacksmithing', 27843),
(2424, -8294.95, 233.033, 7, 99, 0, 'Stormwind Archaeology', 27843),
(91, -8979.49, 763.873, 7, 99, 0, 'Stormwind Alchemy & Herbalism', 27843),
(5212, -9006.62, 869.36, 7, 99, 0, 'Stormwind Portal to Blasted Lands', 27843),
(5214, -8198.92, 527.933, 7, 99, 0, 'Stormwind Portal to Paw\'don Village', 27843),
(2518, -8209.47, 428.528, 7, 99, 0, 'Stormwind Cataclysm Portals', 27843),
(5216, -8300.32, 1400.95, 7, 99, 0, 'Stormwind Ship to Valiance Keep', 27843),
(5213, -9015.66, 874.699, 7, 99, 0, 'Stormwind Portal to Hellfire Peninsula', 27843),
(5215, -8640.37, 1327.42, 7, 99, 0, 'Stormwind Ship to Rut\'theran Village', 27843),
(532, -8394.28, 560.927, 7, 99, 0, 'Stormwind Tram', 27843),
(2420, -8432.65, 319.663, 7, 99, 0, 'Stormwind Keep', 27843),
(2110, -8573.47, 990.095, 7, 0, 0, 'Stormwind Harbor', 27843),
(2421, -8789.09, 827.214, 7, 99, 0, 'Stormwind Stockade', 27843),
(72, -8766.67, 1033.05, 7, 99, 0, 'Lion\'s Rest', 27843),
(1467, -8764.14, 404.2, 7, 99, 0, 'Stormwind Champions\' Hall', 27843),
(2419, -8371.78, 604.283, 7, 99, 0, 'Stormwind Inn', 27843),
(529, -8862.7, 665.363, 7, 99, 0, 'Stormwind Inn', 27843),
(2415, -8327.83, 598.797, 7, 99, 0, 'Stormwind Bank', 27843),
(47, -8900.59, 632.021, 7, 99, 0, 'Stormwind Bank', 27843),
(2416, -8363.9, 658.161, 7, 99, 0, 'Stormwind Auction House', 27843),
(527, -8832.65, 652.766, 7, 99, 0, 'Stormwind Auction House', 27843),
(87, -8887.54, 602.309, 7, 99, 0, 'Stormwind Guild Master', 27843),
(67, -8839.34, 487.552, 7, 99, 0, 'Stormwind Flight Master', 27843),
(2766, -8182.733, 545.3889, 7, 99, 0, 'Stormwind Monk Trainer', 27843),
(70, -8788.16, 344.498, 7, 99, 0, 'Stormwind Warrior & Hunter Trainer', 27843),
(75, -8945.1, 991.033, 7, 99, 0, 'Stormwind Warlock Trainer', 27843),
(1986, -8356.92, 574.814, 7, 99, 0, 'Stormwind Shaman Trainer', 27843),
(69, -8716.23, 328.47, 7, 99, 0, 'Stormwind Rogue Trainer', 27843),
(73, -8582.43, 806.635, 7, 99, 0, 'Stormwind Cathedral', 27843),
(71, -9010.27, 852.878, 7, 99, 0, 'Stormwind Mage Trainer', 27843),
(74, -8424.14, 551.444, 7, 99, 0, 'Stormwind Hunter Trainer', 27843),
(2417, -8282.65, 716.852, 7, 99, 0, 'Stormwind Druid Trainer', 27843),
(2202, -8755.01, 657.7, 7, 99, 0, 'Stormwind Barber', 27843),
(2714, -8697.185, 847.6458, 7, 99, 0, 'The Three Winds', 27843),
(2887, -8287.219, 515.5816, 7, 99, 0, 'Stormwind Battle Pet Trainer', 27843),
(2800, 725.7101, 234.4774, 7, 99, 0, 'Shrine of Seven Stars Ethereal Corridor', 27377),
(2886, 1461.167, -2498.797, 7, 0, 0, 'The Arboretum Order of the Cloud Serpent Quartermaster', 27377),
(2839, -1469.991, -260.474, 7, 0, 0, 'Anglers Wharf Anglers Quartermaster', 27377),
(2844, 1453.361, 405.4688, 7, 0, 0, 'Seat of Knowledge Lorewalkers Quartermaster', 27377),
(2796, 769.8594, 267.4531, 7, 99, 0, 'Shrine of Seven Stars Trade Goods', 27377),
(2956, 823.0087, 207.0313, 7, 99, 0, 'Shrine of Seven Stars Tailor', 27377),
(2858, 841.1042, 252.717, 7, 99, 0, 'Shrine of Seven Stars Sweets', 27377),
(2798, 829.434, 184.8524, 7, 99, 0, 'Shrine of Seven Stars Reagents', 27377),
(2807, 802.9879, 186.8021, 7, 99, 0, 'Shrine of Seven Stars Mining Supplies', 27377),
(2815, 862.3281, 223.8559, 7, 99, 0, 'Shrine of Seven Stars Meats', 27377),
(2857, 815.3594, 175.3889, 7, 99, 0, 'Shrine of Seven Stars Leatherworking', 27377),
(2811, 811.3941, 198.1129, 7, 99, 0, 'Shrine of Seven Stars Jewelers', 27377),
(2802, 825.4688, 205.9132, 7, 99, 0, 'Shrine of Seven Stars Inscription Supplies', 27377),
(2803, 848.4167, 206.0868, 7, 99, 0, 'Shrine of Seven Stars Herb Garden', 27377),
(2797, 783.842, 275.559, 7, 99, 0, 'Shrine of Seven Stars General Goods', 27377),
(2812, 777.4114, 269.8802, 7, 99, 0, 'Shrine of Seven Stars Food & Drink', 27377),
(2856, 938.9427, 292.0191, 7, 99, 0, 'Shrine of Seven Stars Fishing', 27377),
(2810, 793.3733, 251.9444, 7, 99, 0, 'Shrine of Seven Stars First Aid Supplies', 27377),
(2820, 939.9566, 324.9983, 7, 99, 0, 'Shrine of Seven Stars Fireworks Vendor', 27377),
(2808, 810.9549, 220.1424, 7, 99, 0, 'Shrine of Seven Stars Engineering Supplies', 27377),
(2801, 822.1684, 203.5469, 7, 99, 0, 'Shrine of Seven Stars Enchanting Goods', 27377),
(2805, 852.3229, 212.3056, 7, 99, 0, 'Shrine of Seven Stars Cooking Corner', 27377),
(2813, 821.8455, 253.4792, 7, 99, 0, 'Shrine of Seven Stars Brews', 27377),
(2814, 856.5538, 226.1962, 7, 99, 0, 'Shrine of Seven Stars Bakery', 27377),
(2806, 813.6962, 188.9688, 7, 99, 0, 'Shrine of Seven Stars Blacksmithy', 27377),
(2804, 828.9844, 209.8767, 7, 99, 0, 'Shrine of Seven Stars Apothecary', 27377),
(2795, 876.908, 338.2309, 7, 99, 0, 'Shrine of Seven Stars Stable Master', 27377),
(2845, -258.2188, 599.3455, 7, 0, 0, 'Halfhill Tillers Quartermaster', 27377),
(2881, 1856.34, 4274.068, 7, 0, 0, 'Shado-Pan Garrison Quartermaster', 27377),
(2843, 149.9236, 3193.011, 7, 0, 0, 'Klaxxi\'vess Klaxxi Quartermaster', 27377),
(2842, 888.4063, 346.8524, 7, 0, 0, 'Mogu\'shan Palace Golden Lotus Quartermaster - Alliance', 27377),
(2840, 870.3333, 337.1649, 7, 99, 0, 'Shrine of Seven Stars August Celestials Quartermaster', 27377),
(2837, 2084.592, 4903.283, 194, 4231, 0, 'Valor & Justice Quartermaster', 27377),
(2838, 2083.97, 4900.018, 7, 0, 0, 'Niuzao Temple Justice Quartermaster', 27377),
(2882, 200.5556, 2203.135, 46, 4231, 0, 'Conquest & Honor Quartermaster', 27377),
(2835, 200.5556, 2203.135, 7, 0, 0, 'Serpent\'s Spine Alliance Conquest Quartermasters', 27377),
(2833, -466.4288, 219.7326, 7, 0, 0, 'Silken Fields Tailoring', 27377),
(2827, -1078.097, 2054.267, 7, 0, 0, 'Nesingwary\'s Safari Skinning', 27377),
(2832, 2283.715, -1764.807, 7, 0, 0, 'Greenstone Quarry Mining', 27377),
(2831, 2025.571, -1905.21, 7, 0, 0, 'Greenstone Village Jewelcrafting', 27377),
(2830, 1464.674, 406.3906, 7, 0, 0, 'Seat of Knowledge Inscription', 27377),
(2829, -1469.734, -261.8681, 7, 0, 0, 'Anglers Wharf Fishing', 27377),
(2828, 790.5851, 255.5295, 7, 99, 0, 'Shrine of Seven Stars First Aid', 27377),
(2826, -1079.483, 2048.707, 7, 0, 0, 'Nesingwary\'s Safari Engineering', 27377),
(2825, 1656.757, -1817.516, 7, 0, 0, 'Dawn\'s Blossom Enchanting', 27377),
(2824, -256.1441, 611.6059, 7, 0, 0, 'Halfhill Cooking', 27377),
(2823, 726.5486, 1928.281, 7, 0, 0, 'Setting Sun Garrison Blacksmith', 27377),
(2822, 1421.056, 364.2743, 7, 0, 0, 'Seat of Knowledge Archaeology', 27377),
(2821, 156.8837, 3162.639, 7, 0, 0, 'Klaxxi\'vess Alchemy', 27377),
(2819, 935.75, 288.875, 7, 99, 0, 'Shrine of Seven Stars Pet Battle Trainer', 27377),
(2794, 783.9983, 279.724, 7, 99, 0, 'Shrine of Seven Stars Inn', 27377),
(2793, 895.092, 338.1181, 7, 99, 0, 'Shrine of Seven Stars Flight Master', 27377),
(2792, 754.0625, 269.1354, 7, 99, 0, 'Shrine of Seven Stars Bank', 27377);


DELETE FROM `gossip_menu` WHERE (`MenuId`=18491 AND `TextId`=26718) OR (`MenuId`=18486 AND `TextId`=26710) OR (`MenuId`=18326 AND `TextId`=26371) OR (`MenuId`=18488 AND `TextId`=26713) OR (`MenuId`=18542 AND `TextId`=26820) OR (`MenuId`=17051 AND `TextId`=24993) OR (`MenuId`=16872 AND `TextId`=24532) OR (`MenuId`=16707 AND `TextId`=24275) OR (`MenuId`=16877 AND `TextId`=24541) OR (`MenuId`=16718 AND `TextId`=25242) OR (`MenuId`=16283 AND `TextId`=23554) OR (`MenuId`=16597 AND `TextId`=7778) OR (`MenuId`=17231 AND `TextId`=25502) OR (`MenuId`=16897 AND `TextId`=24584) OR (`MenuId`=17055 AND `TextId`=20298) OR (`MenuId`=17431 AND `TextId`=25004) OR (`MenuId`=16864 AND `TextId`=20298) OR (`MenuId`=18201 AND `TextId`=24624) OR (`MenuId`=18292 AND `TextId`=26305) OR (`MenuId`=18268 AND `TextId`=26327) OR (`MenuId`=16811 AND `TextId`=24440) OR (`MenuId`=16514 AND `TextId`=23987) OR (`MenuId`=16595 AND `TextId`=24097) OR (`MenuId`=16585 AND `TextId`=24088) OR (`MenuId`=16592 AND `TextId`=24095) OR (`MenuId`=16781 AND `TextId`=24401) OR (`MenuId`=16588 AND `TextId`=24091) OR (`MenuId`=16780 AND `TextId`=24400) OR (`MenuId`=16779 AND `TextId`=24397) OR (`MenuId`=16783 AND `TextId`=24402) OR (`MenuId`=16594 AND `TextId`=24096) OR (`MenuId`=16829 AND `TextId`=24465) OR (`MenuId`=16825 AND `TextId`=24461) OR (`MenuId`=16823 AND `TextId`=24459) OR (`MenuId`=16586 AND `TextId`=24089) OR (`MenuId`=16802 AND `TextId`=24432) OR (`MenuId`=16423 AND `TextId`=23871) OR (`MenuId`=16422 AND `TextId`=23874) OR (`MenuId`=16902 AND `TextId`=24589) OR (`MenuId`=17317 AND `TextId`=25715) OR (`MenuId`=17984 AND `TextId`=25930) OR (`MenuId`=17272 AND `TextId`=25562) OR (`MenuId`=17266 AND `TextId`=25551) OR (`MenuId`=17418 AND `TextId`=25882) OR (`MenuId`=16873 AND `TextId`=24536) OR (`MenuId`=17253 AND `TextId`=25528) OR (`MenuId`=17249 AND `TextId`=25524) OR (`MenuId`=17257 AND `TextId`=25532) OR (`MenuId`=17251 AND `TextId`=25526) OR (`MenuId`=16894 AND `TextId`=24572) OR (`MenuId`=17042 AND `TextId`=24953) OR (`MenuId`=16794 AND `TextId`=24418) OR (`MenuId`=16537 AND `TextId`=24019) OR (`MenuId`=16548 AND `TextId`=24034) OR (`MenuId`=16544 AND `TextId`=24030) OR (`MenuId`=16001 AND `TextId`=24028) OR (`MenuId`=16544 AND `TextId`=24029) OR (`MenuId`=18287 AND `TextId`=25004) OR (`MenuId`=16916 AND `TextId`=24619) OR (`MenuId`=16452 AND `TextId`=23849) OR (`MenuId`=16632 AND `TextId`=24161) OR (`MenuId`=16631 AND `TextId`=24160) OR (`MenuId`=16771 AND `TextId`=24378) OR (`MenuId`=16659 AND `TextId`=24198) OR (`MenuId`=16656 AND `TextId`=24194) OR (`MenuId`=16728 AND `TextId`=24326) OR (`MenuId`=16653 AND `TextId`=24190) OR (`MenuId`=16513 AND `TextId`=23986) OR (`MenuId`=16492 AND `TextId`=23944) OR (`MenuId`=16494 AND `TextId`=23953) OR (`MenuId`=16511 AND `TextId`=23983) OR (`MenuId`=16732 AND `TextId`=24328) OR (`MenuId`=16903 AND `TextId`=24590) OR (`MenuId`=16904 AND `TextId`=24591) OR (`MenuId`=17293 AND `TextId`=25634) OR (`MenuId`=17357 AND `TextId`=25809) OR (`MenuId`=16666 AND `TextId`=24205) OR (`MenuId`=16481 AND `TextId`=23912) OR (`MenuId`=16606 AND `TextId`=24124) OR (`MenuId`=16467 AND `TextId`=23920) OR (`MenuId`=16466 AND `TextId`=23882) OR (`MenuId`=16414 AND `TextId`=23779) OR (`MenuId`=16416 AND `TextId`=23783) OR (`MenuId`=16457 AND `TextId`=23862) OR (`MenuId`=16437 AND `TextId`=23829) OR (`MenuId`=16569 AND `TextId`=24066) OR (`MenuId`=16570 AND `TextId`=24067) OR (`MenuId`=16456 AND `TextId`=23861) OR (`MenuId`=16654 AND `TextId`=24191) OR (`MenuId`=16695 AND `TextId`=24256) OR (`MenuId`=16483 AND `TextId`=23883) OR (`MenuId`=16837 AND `TextId`=24480) OR (`MenuId`=16704 AND `TextId`=24273) OR (`MenuId`=18167 AND `TextId`=26094) OR (`MenuId`=17322 AND `TextId`=25764) OR (`MenuId`=16506 AND `TextId`=23973) OR (`MenuId`=16423 AND `TextId`=23796) OR (`MenuId`=16422 AND `TextId`=23795) OR (`MenuId`=16426 AND `TextId`=23803) OR (`MenuId`=16427 AND `TextId`=23804) OR (`MenuId`=16722 AND `TextId`=24305) OR (`MenuId`=16721 AND `TextId`=24303) OR (`MenuId`=16668 AND `TextId`=24207) OR (`MenuId`=16697 AND `TextId`=24266) OR (`MenuId`=16798 AND `TextId`=24426) OR (`MenuId`=16650 AND `TextId`=24186) OR (`MenuId`=16742 AND `TextId`=24343) OR (`MenuId`=16875 AND `TextId`=24539) OR (`MenuId`=16640 AND `TextId`=24169) OR (`MenuId`=16718 AND `TextId`=24296) OR (`MenuId`=17296 AND `TextId`=25638) OR (`MenuId`=16696 AND `TextId`=24261) OR (`MenuId`=17275 AND `TextId`=25567) OR (`MenuId`=16819 AND `TextId`=24453) OR (`MenuId`=16831 AND `TextId`=24467) OR (`MenuId`=16832 AND `TextId`=24468) OR (`MenuId`=17043 AND `TextId`=24954) OR (`MenuId`=17201 AND `TextId`=25426) OR (`MenuId`=16718 AND `TextId`=24295) OR (`MenuId`=17985 AND `TextId`=25930) OR (`MenuId`=17107 AND `TextId`=25151) OR (`MenuId`=16476 AND `TextId`=23905) OR (`MenuId`=16476 AND `TextId`=23904) OR (`MenuId`=16575 AND `TextId`=24076) OR (`MenuId`=16575 AND `TextId`=24075) OR (`MenuId`=16684 AND `TextId`=24232) OR (`MenuId`=16596 AND `TextId`=24099) OR (`MenuId`=16993 AND `TextId`=24737) OR (`MenuId`=16646 AND `TextId`=24251) OR (`MenuId`=16596 AND `TextId`=24717) OR (`MenuId`=16626 AND `TextId`=24154) OR (`MenuId`=16913 AND `TextId`=24616) OR (`MenuId`=16571 AND `TextId`=24070) OR (`MenuId`=16957 AND `TextId`=24674) OR (`MenuId`=16688 AND `TextId`=24240) OR (`MenuId`=16617 AND `TextId`=24140) OR (`MenuId`=16834 AND `TextId`=24476) OR (`MenuId`=16835 AND `TextId`=24477) OR (`MenuId`=16836 AND `TextId`=24478) OR (`MenuId`=18677 AND `TextId`=27140) OR (`MenuId`=18779 AND `TextId`=27322) OR (`MenuId`=17531 AND `TextId`=24916) OR (`MenuId`=17422 AND `TextId`=24851) OR (`MenuId`=17306 AND `TextId`=25678) OR (`MenuId`=18372 AND `TextId`=26457) OR (`MenuId`=17319 AND `TextId`=25730) OR (`MenuId`=16613 AND `TextId`=24441) OR (`MenuId`=16390 AND `TextId`=23761) OR (`MenuId`=16670 AND `TextId`=24209) OR (`MenuId`=18371 AND `TextId`=26456) OR (`MenuId`=16998 AND `TextId`=9051) OR (`MenuId`=17010 AND `TextId`=24806) OR (`MenuId`=18322 AND `TextId`=26356) OR (`MenuId`=16905 AND `TextId`=24599) OR (`MenuId`=18566 AND `TextId`=26888) OR (`MenuId`=17354 AND `TextId`=25806) OR (`MenuId`=17330 AND `TextId`=25783) OR (`MenuId`=17177 AND `TextId`=25069) OR (`MenuId`=16518 AND `TextId`=23994) OR (`MenuId`=16432 AND `TextId`=23823) OR (`MenuId`=16429 AND `TextId`=23809) OR (`MenuId`=16433 AND `TextId`=23824) OR (`MenuId`=16428 AND `TextId`=23808) OR (`MenuId`=16405 AND `TextId`=23740) OR (`MenuId`=16641 AND `TextId`=24170) OR (`MenuId`=16376 AND `TextId`=23740) OR (`MenuId`=16693 AND `TextId`=24252) OR (`MenuId`=16863 AND `TextId`=24524) OR (`MenuId`=16910 AND `TextId`=24613) OR (`MenuId`=16723 AND `TextId`=24306) OR (`MenuId`=13723 AND `TextId`=19717) OR (`MenuId`=13724 AND `TextId`=19719) OR (`MenuId`=13822 AND `TextId`=19954) OR (`MenuId`=13823 AND `TextId`=19955) OR (`MenuId`=20992 AND `TextId`=31666) OR (`MenuId`=13843 AND `TextId`=19992) OR (`MenuId`=14609 AND `TextId`=20669) OR (`MenuId`=14614 AND `TextId`=20673) OR (`MenuId`=14613 AND `TextId`=20672) OR (`MenuId`=13831 AND `TextId`=19995) OR (`MenuId`=13831 AND `TextId`=19991) OR (`MenuId`=13836 AND `TextId`=19999) OR (`MenuId`=13832 AND `TextId`=20004) OR (`MenuId`=13831 AND `TextId`=19994) OR (`MenuId`=13836 AND `TextId`=19972) OR (`MenuId`=13832 AND `TextId`=20003) OR (`MenuId`=13836 AND `TextId`=19973) OR (`MenuId`=13832 AND `TextId`=19982) OR (`MenuId`=13830 AND `TextId`=19966) OR (`MenuId`=13839 AND `TextId`=20001) OR (`MenuId`=13831 AND `TextId`=19967) OR (`MenuId`=13839 AND `TextId`=19987) OR (`MenuId`=13836 AND `TextId`=19986) OR (`MenuId`=13832 AND `TextId`=19968) OR (`MenuId`=13831 AND `TextId`=19993) OR (`MenuId`=13678 AND `TextId`=19621) OR (`MenuId`=13681 AND `TextId`=19625) OR (`MenuId`=13680 AND `TextId`=19624) OR (`MenuId`=13683 AND `TextId`=19939) OR (`MenuId`=13683 AND `TextId`=19938) OR (`MenuId`=13683 AND `TextId`=19630) OR (`MenuId`=13794 AND `TextId`=19878) OR (`MenuId`=13795 AND `TextId`=19879) OR (`MenuId`=13720 AND `TextId`=19712) OR (`MenuId`=13712 AND `TextId`=19740) OR (`MenuId`=14485 AND `TextId`=20430) OR (`MenuId`=13893 AND `TextId`=20079) OR (`MenuId`=13892 AND `TextId`=20017) OR (`MenuId`=13796 AND `TextId`=19881) OR (`MenuId`=15055 AND `TextId`=19352) OR (`MenuId`=13712 AND `TextId`=19688) OR (`MenuId`=13694 AND `TextId`=19665) OR (`MenuId`=13686 AND `TextId`=19635) OR (`MenuId`=13685 AND `TextId`=19633) OR (`MenuId`=13467 AND `TextId`=19171) OR (`MenuId`=13462 AND `TextId`=19161) OR (`MenuId`=13464 AND `TextId`=19166) OR (`MenuId`=13745 AND `TextId`=19770) OR (`MenuId`=13301 AND `TextId`=18859) OR (`MenuId`=13301 AND `TextId`=18858) OR (`MenuId`=13437 AND `TextId`=19126) OR (`MenuId`=13301 AND `TextId`=18810) OR (`MenuId`=13310 AND `TextId`=18833) OR (`MenuId`=13310 AND `TextId`=18832) OR (`MenuId`=13318 AND `TextId`=18845) OR (`MenuId`=13317 AND `TextId`=18844) OR (`MenuId`=13320 AND `TextId`=18847) OR (`MenuId`=13316 AND `TextId`=18843) OR (`MenuId`=13311 AND `TextId`=18834) OR (`MenuId`=14635 AND `TextId`=20696) OR (`MenuId`=14317 AND `TextId`=20216) OR (`MenuId`=13748 AND `TextId`=19773) OR (`MenuId`=13747 AND `TextId`=19772) OR (`MenuId`=13746 AND `TextId`=19771) OR (`MenuId`=13420 AND `TextId`=19086) OR (`MenuId`=13424 AND `TextId`=19080) OR (`MenuId`=13421 AND `TextId`=19075) OR (`MenuId`=13420 AND `TextId`=19074) OR (`MenuId`=13423 AND `TextId`=19078) OR (`MenuId`=14323 AND `TextId`=20224) OR (`MenuId`=14795 AND `TextId`=20932) OR (`MenuId`=14324 AND `TextId`=20227) OR (`MenuId`=13379 AND `TextId`=18997) OR (`MenuId`=13378 AND `TextId`=18996) OR (`MenuId`=13398 AND `TextId`=19028) OR (`MenuId`=13398 AND `TextId`=19027) OR (`MenuId`=15003 AND `TextId`=21212) OR (`MenuId`=13622 AND `TextId`=19528) OR (`MenuId`=13470 AND `TextId`=19179) OR (`MenuId`=13749 AND `TextId`=19776) OR (`MenuId`=12380 AND `TextId`=17401) OR (`MenuId`=12380 AND `TextId`=17400) OR (`MenuId`=12377 AND `TextId`=17397) OR (`MenuId`=12602 AND `TextId`=17740) OR (`MenuId`=12130 AND `TextId`=17036) OR (`MenuId`=12059 AND `TextId`=16907) OR (`MenuId`=12143 AND `TextId`=17055) OR (`MenuId`=12141 AND `TextId`=17052) OR (`MenuId`=12142 AND `TextId`=17053) OR (`MenuId`=12140 AND `TextId`=17051) OR (`MenuId`=12139 AND `TextId`=17046) OR (`MenuId`=12138 AND `TextId`=17014) OR (`MenuId`=12116 AND `TextId`=17013) OR (`MenuId`=12115 AND `TextId`=17012) OR (`MenuId`=12114 AND `TextId`=17011) OR (`MenuId`=12135 AND `TextId`=17013) OR (`MenuId`=12136 AND `TextId`=17012) OR (`MenuId`=12137 AND `TextId`=17011) OR (`MenuId`=12160 AND `TextId`=17099) OR (`MenuId`=12165 AND `TextId`=17104) OR (`MenuId`=12166 AND `TextId`=17105) OR (`MenuId`=12247 AND `TextId`=17212) OR (`MenuId`=12247 AND `TextId`=17208) OR (`MenuId`=12266 AND `TextId`=17228) OR (`MenuId`=12159 AND `TextId`=17098) OR (`MenuId`=12157 AND `TextId`=17096) OR (`MenuId`=12057 AND `TextId`=16906) OR (`MenuId`=12387 AND `TextId`=17409) OR (`MenuId`=12057 AND `TextId`=16903) OR (`MenuId`=18639 AND `TextId`=27072) OR (`MenuId`=12362 AND `TextId`=17367) OR (`MenuId`=12164 AND `TextId`=17103) OR (`MenuId`=15067 AND `TextId`=21297) OR (`MenuId`=12158 AND `TextId`=17097) OR (`MenuId`=12042 AND `TextId`=16872) OR (`MenuId`=12036 AND `TextId`=16867) OR (`MenuId`=11944 AND `TextId`=16766) OR (`MenuId`=12386 AND `TextId`=17407) OR (`MenuId`=11522 AND `TextId`=16032) OR (`MenuId`=11489 AND `TextId`=16033) OR (`MenuId`=11513 AND `TextId`=16067) OR (`MenuId`=11514 AND `TextId`=16066) OR (`MenuId`=11510 AND `TextId`=16064) OR (`MenuId`=11511 AND `TextId`=16063) OR (`MenuId`=11508 AND `TextId`=16062) OR (`MenuId`=11509 AND `TextId`=16061) OR (`MenuId`=11327 AND `TextId`=15783) OR (`MenuId`=12122 AND `TextId`=17027) OR (`MenuId`=12118 AND `TextId`=17020) OR (`MenuId`=11478 AND `TextId`=16015) OR (`MenuId`=11314 AND `TextId`=17002) OR (`MenuId`=11314 AND `TextId`=15770) OR (`MenuId`=11444 AND `TextId`=15943) OR (`MenuId`=11442 AND `TextId`=15938) OR (`MenuId`=12213 AND `TextId`=17166) OR (`MenuId`=18536 AND `TextId`=6957) OR (`MenuId`=18542 AND `TextId`=27070) OR (`MenuId`=18253 AND `TextId`=7778) OR (`MenuId`=18260 AND `TextId`=26263) OR (`MenuId`=18599 AND `TextId`=26967) OR (`MenuId`=18269 AND `TextId`=26274) OR (`MenuId`=18437 AND `TextId`=26601) OR (`MenuId`=18416 AND `TextId`=26551) OR (`MenuId`=18335 AND `TextId`=26388) OR (`MenuId`=18334 AND `TextId`=26389) OR (`MenuId`=18263 AND `TextId`=26266) OR (`MenuId`=18331 AND `TextId`=26384) OR (`MenuId`=18333 AND `TextId`=26386) OR (`MenuId`=18332 AND `TextId`=26387) OR (`MenuId`=18415 AND `TextId`=26550) OR (`MenuId`=18330 AND `TextId`=26385) OR (`MenuId`=18412 AND `TextId`=26542) OR (`MenuId`=18413 AND `TextId`=26543) OR (`MenuId`=18620 AND `TextId`=27007) OR (`MenuId`=18620 AND `TextId`=27016) OR (`MenuId`=18228 AND `TextId`=26181) OR (`MenuId`=18227 AND `TextId`=26182) OR (`MenuId`=18670 AND `TextId`=27101) OR (`MenuId`=18670 AND `TextId`=27136) OR (`MenuId`=17542 AND `TextId`=24901) OR (`MenuId`=17038 AND `TextId`=24900) OR (`MenuId`=16353 AND `TextId`=23687) OR (`MenuId`=16357 AND `TextId`=23695) OR (`MenuId`=16367 AND `TextId`=23695) OR (`MenuId`=16354 AND `TextId`=23689) OR (`MenuId`=16352 AND `TextId`=23686) OR (`MenuId`=18375 AND `TextId`=26464) OR (`MenuId`=16313 AND `TextId`=23606) OR (`MenuId`=16312 AND `TextId`=23606) OR (`MenuId`=16399 AND `TextId`=23766) OR (`MenuId`=16308 AND `TextId`=23598) OR (`MenuId`=16398 AND `TextId`=23766) OR (`MenuId`=16633 AND `TextId`=24162) OR (`MenuId`=16616 AND `TextId`=24138) OR (`MenuId`=16634 AND `TextId`=24163) OR (`MenuId`=16635 AND `TextId`=24164) OR (`MenuId`=16642 AND `TextId`=24171) OR (`MenuId`=16637 AND `TextId`=24166) OR (`MenuId`=16627 AND `TextId`=24155) OR (`MenuId`=16629 AND `TextId`=24157) OR (`MenuId`=16528 AND `TextId`=24009) OR (`MenuId`=16648 AND `TextId`=24181) OR (`MenuId`=16630 AND `TextId`=24158) OR (`MenuId`=16447 AND `TextId`=23841) OR (`MenuId`=16448 AND `TextId`=23843) OR (`MenuId`=16316 AND `TextId`=23614) OR (`MenuId`=16401 AND `TextId`=23767) OR (`MenuId`=16160 AND `TextId`=23330) OR (`MenuId`=16692 AND `TextId`=24250) OR (`MenuId`=17110 AND `TextId`=25154) OR (`MenuId`=16850 AND `TextId`=24552) OR (`MenuId`=16814 AND `TextId`=24506) OR (`MenuId`=16878 AND `TextId`=24547) OR (`MenuId`=17094 AND `TextId`=25130) OR (`MenuId`=16298 AND `TextId`=23555) OR (`MenuId`=16500 AND `TextId`=23959) OR (`MenuId`=16501 AND `TextId`=23960) OR (`MenuId`=16499 AND `TextId`=23958) OR (`MenuId`=16498 AND `TextId`=23957) OR (`MenuId`=16392 AND `TextId`=23762) OR (`MenuId`=16486 AND `TextId`=23931) OR (`MenuId`=16604 AND `TextId`=24118) OR (`MenuId`=16383 AND `TextId`=23754) OR (`MenuId`=16987 AND `TextId`=24726) OR (`MenuId`=17321 AND `TextId`=25732) OR (`MenuId`=17541 AND `TextId`=24938) OR (`MenuId`=17443 AND `TextId`=24912) OR (`MenuId`=17511 AND `TextId`=24790) OR (`MenuId`=17032 AND `TextId`=24851) OR (`MenuId`=18498 AND `TextId`=26742) OR (`MenuId`=18497 AND `TextId`=26741) OR (`MenuId`=18492 AND `TextId`=26740) OR (`MenuId`=18489 AND `TextId`=26715) OR (`MenuId`=4824 AND `TextId`=5880) OR (`MenuId`=17046 AND `TextId`=24975) OR (`MenuId`=17183 AND `TextId`=25277) OR (`MenuId`=17127 AND `TextId`=25173) OR (`MenuId`=17178 AND `TextId`=25272) OR (`MenuId`=17179 AND `TextId`=25273) OR (`MenuId`=17148 AND `TextId`=25236) OR (`MenuId`=17182 AND `TextId`=25276) OR (`MenuId`=17181 AND `TextId`=25275) OR (`MenuId`=17152 AND `TextId`=25243) OR (`MenuId`=17294 AND `TextId`=25635) OR (`MenuId`=17153 AND `TextId`=25244) OR (`MenuId`=17268 AND `TextId`=25555) OR (`MenuId`=17157 AND `TextId`=25249) OR (`MenuId`=17131 AND `TextId`=25178) OR (`MenuId`=17130 AND `TextId`=25176) OR (`MenuId`=17334 AND `TextId`=25786) OR (`MenuId`=17312 AND `TextId`=25685) OR (`MenuId`=18324 AND `TextId`=26967) OR (`MenuId`=17044 AND `TextId`=24955) OR (`MenuId`=17156 AND `TextId`=25248) OR (`MenuId`=17047 AND `TextId`=24981) OR (`MenuId`=17048 AND `TextId`=24982) OR (`MenuId`=17126 AND `TextId`=25172) OR (`MenuId`=18275 AND `TextId`=26286) OR (`MenuId`=18276 AND `TextId`=26287) OR (`MenuId`=17049 AND `TextId`=24983) OR (`MenuId`=17245 AND `TextId`=25519) OR (`MenuId`=17277 AND `TextId`=25570) OR (`MenuId`=17128 AND `TextId`=25174) OR (`MenuId`=17336 AND `TextId`=25788) OR (`MenuId`=17375 AND `TextId`=25828) OR (`MenuId`=17372 AND `TextId`=25824) OR (`MenuId`=17373 AND `TextId`=25826) OR (`MenuId`=17374 AND `TextId`=25827) OR (`MenuId`=17337 AND `TextId`=25789) OR (`MenuId`=17371 AND `TextId`=25825) OR (`MenuId`=17370 AND `TextId`=25823) OR (`MenuId`=17367 AND `TextId`=25820) OR (`MenuId`=17349 AND `TextId`=25801) OR (`MenuId`=17369 AND `TextId`=25822) OR (`MenuId`=17368 AND `TextId`=25821) OR (`MenuId`=17366 AND `TextId`=25819) OR (`MenuId`=17365 AND `TextId`=25818) OR (`MenuId`=17364 AND `TextId`=25817) OR (`MenuId`=17363 AND `TextId`=25816) OR (`MenuId`=17362 AND `TextId`=25815) OR (`MenuId`=17361 AND `TextId`=25814) OR (`MenuId`=17356 AND `TextId`=25808) OR (`MenuId`=17355 AND `TextId`=25807) OR (`MenuId`=17353 AND `TextId`=25805) OR (`MenuId`=17352 AND `TextId`=25804) OR (`MenuId`=17351 AND `TextId`=25803) OR (`MenuId`=17350 AND `TextId`=25802) OR (`MenuId`=17335 AND `TextId`=25787) OR (`MenuId`=17347 AND `TextId`=25800) OR (`MenuId`=17348 AND `TextId`=25797) OR (`MenuId`=17346 AND `TextId`=25799) OR (`MenuId`=17345 AND `TextId`=25798) OR (`MenuId`=17343 AND `TextId`=25796) OR (`MenuId`=17344 AND `TextId`=25793) OR (`MenuId`=17342 AND `TextId`=25795) OR (`MenuId`=17341 AND `TextId`=25794) OR (`MenuId`=17340 AND `TextId`=25792) OR (`MenuId`=17339 AND `TextId`=25791) OR (`MenuId`=17338 AND `TextId`=25790) OR (`MenuId`=16355 AND `TextId`=23691) OR (`MenuId`=16365 AND `TextId`=23713) OR (`MenuId`=17280 AND `TextId`=25591) OR (`MenuId`=16601 AND `TextId`=24106) OR (`MenuId`=17288 AND `TextId`=25609) OR (`MenuId`=17009 AND `TextId`=24761) OR (`MenuId`=17000 AND `TextId`=24747) OR (`MenuId`=17271 AND `TextId`=24619) OR (`MenuId`=16257 AND `TextId`=23510) OR (`MenuId`=17535 AND `TextId`=24930) OR (`MenuId`=16430 AND `TextId`=23810) OR (`MenuId`=16975 AND `TextId`=24707) OR (`MenuId`=16974 AND `TextId`=24705) OR (`MenuId`=17197 AND `TextId`=25421) OR (`MenuId`=17308 AND `TextId`=25680) OR (`MenuId`=17089 AND `TextId`=9849) OR (`MenuId`=16118 AND `TextId`=23221) OR (`MenuId`=16292 AND `TextId`=23572) OR (`MenuId`=16535 AND `TextId`=23509) OR (`MenuId`=17092 AND `TextId`=25125) OR (`MenuId`=16465 AND `TextId`=23880) OR (`MenuId`=16119 AND `TextId`=23222) OR (`MenuId`=16254 AND `TextId`=23507) OR (`MenuId`=16148 AND `TextId`=23279) OR (`MenuId`=16556 AND `TextId`=24048) OR (`MenuId`=16555 AND `TextId`=24047) OR (`MenuId`=17426 AND `TextId`=25004) OR (`MenuId`=16482 AND `TextId`=23915) OR (`MenuId`=16487 AND `TextId`=23932) OR (`MenuId`=16258 AND `TextId`=23511) OR (`MenuId`=16236 AND `TextId`=23470) OR (`MenuId`=16868 AND `TextId`=24528) OR (`MenuId`=16797 AND `TextId`=24424) OR (`MenuId`=16739 AND `TextId`=24338) OR (`MenuId`=16743 AND `TextId`=24341) OR (`MenuId`=16745 AND `TextId`=24347) OR (`MenuId`=16744 AND `TextId`=24344) OR (`MenuId`=16744 AND `TextId`=24345) OR (`MenuId`=16745 AND `TextId`=24346) OR (`MenuId`=16743 AND `TextId`=24342) OR (`MenuId`=16690 AND `TextId`=24246) OR (`MenuId`=16690 AND `TextId`=24245) OR (`MenuId`=17013 AND `TextId`=24819) OR (`MenuId`=16674 AND `TextId`=24218) OR (`MenuId`=16673 AND `TextId`=24217) OR (`MenuId`=16287 AND `TextId`=23564) OR (`MenuId`=16536 AND `TextId`=24018) OR (`MenuId`=16533 AND `TextId`=24014) OR (`MenuId`=16532 AND `TextId`=24013) OR (`MenuId`=16564 AND `TextId`=24061) OR (`MenuId`=16526 AND `TextId`=24007) OR (`MenuId`=16527 AND `TextId`=24008) OR (`MenuId`=16999 AND `TextId`=24745) OR (`MenuId`=16530 AND `TextId`=24011) OR (`MenuId`=16986 AND `TextId`=24725) OR (`MenuId`=16862 AND `TextId`=24521) OR (`MenuId`=16994 AND `TextId`=24741) OR (`MenuId`=17069 AND `TextId`=25079) OR (`MenuId`=16750 AND `TextId`=24349) OR (`MenuId`=18564 AND `TextId`=26884) OR (`MenuId`=17005 AND `TextId`=24751) OR (`MenuId`=16464 AND `TextId`=23878) OR (`MenuId`=17199 AND `TextId`=25423) OR (`MenuId`=16966 AND `TextId`=24692) OR (`MenuId`=16962 AND `TextId`=24678) OR (`MenuId`=16148 AND `TextId`=24180) OR (`MenuId`=16535 AND `TextId`=24017) OR (`MenuId`=17989 AND `TextId`=25930) OR (`MenuId`=16552 AND `TextId`=24038) OR (`MenuId`=16567 AND `TextId`=24064) OR (`MenuId`=16566 AND `TextId`=24063) OR (`MenuId`=16568 AND `TextId`=24065) OR (`MenuId`=16561 AND `TextId`=24056) OR (`MenuId`=7742 AND `TextId`=9478) OR (`MenuId`=15791 AND `TextId`=22682) OR (`MenuId`=16371 AND `TextId`=22846) OR (`MenuId`=16609 AND `TextId`=24131) OR (`MenuId`=15802 AND `TextId`=22706) OR (`MenuId`=15777 AND `TextId`=22665) OR (`MenuId`=17135 AND `TextId`=25183) OR (`MenuId`=16463 AND `TextId`=23877) OR (`MenuId`=17235 AND `TextId`=25477) OR (`MenuId`=17235 AND `TextId`=25479) OR (`MenuId`=16440 AND `TextId`=23832) OR (`MenuId`=17064 AND `TextId`=25072) OR (`MenuId`=16598 AND `TextId`=24100) OR (`MenuId`=16812 AND `TextId`=24135) OR (`MenuId`=16613 AND `TextId`=24135) OR (`MenuId`=16521 AND `TextId`=23999) OR (`MenuId`=16643 AND `TextId`=24172) OR (`MenuId`=16871 AND `TextId`=24531) OR (`MenuId`=16411 AND `TextId`=23776) OR (`MenuId`=16404 AND `TextId`=23771) OR (`MenuId`=13847 AND `TextId`=20112) OR (`MenuId`=14314 AND `TextId`=20213) OR (`MenuId`=14272 AND `TextId`=20119) OR (`MenuId`=14271 AND `TextId`=20118) OR (`MenuId`=14655 AND `TextId`=20732) OR (`MenuId`=14656 AND `TextId`=20733) OR (`MenuId`=13888 AND `TextId`=20075) OR (`MenuId`=15365 AND `TextId`=22050) OR (`MenuId`=14497 AND `TextId`=20504) OR (`MenuId`=14511 AND `TextId`=20518) OR (`MenuId`=14302 AND `TextId`=20177) OR (`MenuId`=14398 AND `TextId`=20322) OR (`MenuId`=14299 AND `TextId`=20497) OR (`MenuId`=14299 AND `TextId`=20496) OR (`MenuId`=14336 AND `TextId`=20243) OR (`MenuId`=14299 AND `TextId`=20171) OR (`MenuId`=14300 AND `TextId`=20173) OR (`MenuId`=14301 AND `TextId`=20174) OR (`MenuId`=14663 AND `TextId`=20763) OR (`MenuId`=14272 AND `TextId`=20751) OR (`MenuId`=14269 AND `TextId`=20116) OR (`MenuId`=14044 AND `TextId`=20099) OR (`MenuId`=14046 AND `TextId`=20100) OR (`MenuId`=14275 AND `TextId`=20121) OR (`MenuId`=15005 AND `TextId`=21214) OR (`MenuId`=15006 AND `TextId`=21213) OR (`MenuId`=14053 AND `TextId`=20103) OR (`MenuId`=14049 AND `TextId`=20102) OR (`MenuId`=14043 AND `TextId`=20098) OR (`MenuId`=14055 AND `TextId`=20104) OR (`MenuId`=14596 AND `TextId`=20637) OR (`MenuId`=14271 AND `TextId`=20139) OR (`MenuId`=14271 AND `TextId`=20138) OR (`MenuId`=15049 AND `TextId`=21284) OR (`MenuId`=14484 AND `TextId`=20429) OR (`MenuId`=14484 AND `TextId`=20428) OR (`MenuId`=13847 AND `TextId`=20061) OR (`MenuId`=14668 AND `TextId`=20769) OR (`MenuId`=14667 AND `TextId`=20768) OR (`MenuId`=14666 AND `TextId`=20767) OR (`MenuId`=14665 AND `TextId`=20766) OR (`MenuId`=14664 AND `TextId`=20765) OR (`MenuId`=14807 AND `TextId`=20955) OR (`MenuId`=14641 AND `TextId`=20703) OR (`MenuId`=13847 AND `TextId`=20022) OR (`MenuId`=13847 AND `TextId`=20015) OR (`MenuId`=13838 AND `TextId`=19983) OR (`MenuId`=13837 AND `TextId`=19978) OR (`MenuId`=13882 AND `TextId`=20067) OR (`MenuId`=13883 AND `TextId`=20068) OR (`MenuId`=13848 AND `TextId`=20011) OR (`MenuId`=13894 AND `TextId`=20082) OR (`MenuId`=13894 AND `TextId`=20080) OR (`MenuId`=13841 AND `TextId`=19989) OR (`MenuId`=13877 AND `TextId`=20053) OR (`MenuId`=13876 AND `TextId`=20052) OR (`MenuId`=13874 AND `TextId`=20050) OR (`MenuId`=13875 AND `TextId`=20051) OR (`MenuId`=15090 AND `TextId`=21469) OR (`MenuId`=13842 AND `TextId`=19990) OR (`MenuId`=15321 AND `TextId`=21239) OR (`MenuId`=15570 AND `TextId`=22365) OR (`MenuId`=15577 AND `TextId`=22374) OR (`MenuId`=15576 AND `TextId`=22373) OR (`MenuId`=15516 AND `TextId`=22278) OR (`MenuId`=14278 AND `TextId`=20124) OR (`MenuId`=14307 AND `TextId`=20190) OR (`MenuId`=14306 AND `TextId`=20189) OR (`MenuId`=14529 AND `TextId`=20540) OR (`MenuId`=14996 AND `TextId`=21205) OR (`MenuId`=13849 AND `TextId`=20012) OR (`MenuId`=13884 AND `TextId`=20071) OR (`MenuId`=14276 AND `TextId`=20122) OR (`MenuId`=13844 AND `TextId`=20007) OR (`MenuId`=14798 AND `TextId`=20937) OR (`MenuId`=13846 AND `TextId`=20006) OR (`MenuId`=13845 AND `TextId`=20005) OR (`MenuId`=14846 AND `TextId`=21006) OR (`MenuId`=13826 AND `TextId`=19962) OR (`MenuId`=13825 AND `TextId`=19961) OR (`MenuId`=13804 AND `TextId`=19897) OR (`MenuId`=13828 AND `TextId`=19964) OR (`MenuId`=13827 AND `TextId`=19963) OR (`MenuId`=13781 AND `TextId`=19862) OR (`MenuId`=13799 AND `TextId`=19886) OR (`MenuId`=13798 AND `TextId`=19885) OR (`MenuId`=13797 AND `TextId`=19884) OR (`MenuId`=13804 AND `TextId`=19896) OR (`MenuId`=13731 AND `TextId`=19733) OR (`MenuId`=13731 AND `TextId`=19732) OR (`MenuId`=13731 AND `TextId`=19731) OR (`MenuId`=13731 AND `TextId`=19730) OR (`MenuId`=13739 AND `TextId`=19808) OR (`MenuId`=13762 AND `TextId`=19819) OR (`MenuId`=13734 AND `TextId`=19809) OR (`MenuId`=13762 AND `TextId`=19818) OR (`MenuId`=13739 AND `TextId`=19806) OR (`MenuId`=13739 AND `TextId`=19764) OR (`MenuId`=13762 AND `TextId`=19817) OR (`MenuId`=13734 AND `TextId`=19743) OR (`MenuId`=13739 AND `TextId`=19763) OR (`MenuId`=13722 AND `TextId`=19721) OR (`MenuId`=13730 AND `TextId`=19746) OR (`MenuId`=13729 AND `TextId`=19745) OR (`MenuId`=13730 AND `TextId`=19749) OR (`MenuId`=13735 AND `TextId`=19747) OR (`MenuId`=13733 AND `TextId`=19742) OR (`MenuId`=13722 AND `TextId`=19718) OR (`MenuId`=13729 AND `TextId`=19727) OR (`MenuId`=13730 AND `TextId`=19729) OR (`MenuId`=13728 AND `TextId`=19725) OR (`MenuId`=13729 AND `TextId`=19726) OR (`MenuId`=13730 AND `TextId`=19728) OR (`MenuId`=14636 AND `TextId`=20697) OR (`MenuId`=14599 AND `TextId`=20653) OR (`MenuId`=14600 AND `TextId`=20656) OR (`MenuId`=14567 AND `TextId`=20590) OR (`MenuId`=13753 AND `TextId`=19786) OR (`MenuId`=13810 AND `TextId`=19856) OR (`MenuId`=13778 AND `TextId`=19858) OR (`MenuId`=13777 AND `TextId`=19856) OR (`MenuId`=14595 AND `TextId`=20636) OR (`MenuId`=15041 AND `TextId`=21276) OR (`MenuId`=21666 AND `TextId`=32996) OR (`MenuId`=13865 AND `TextId`=20034) OR (`MenuId`=14954 AND `TextId`=21144) OR (`MenuId`=14961 AND `TextId`=21152) OR (`MenuId`=14956 AND `TextId`=21147) OR (`MenuId`=14957 AND `TextId`=21148) OR (`MenuId`=14993 AND `TextId`=21198) OR (`MenuId`=14992 AND `TextId`=21197) OR (`MenuId`=14986 AND `TextId`=21184) OR (`MenuId`=15612 AND `TextId`=22422) OR (`MenuId`=14994 AND `TextId`=21199) OR (`MenuId`=13718 AND `TextId`=19683) OR (`MenuId`=13711 AND `TextId`=19752) OR (`MenuId`=13718 AND `TextId`=19720) OR (`MenuId`=14867 AND `TextId`=21028) OR (`MenuId`=15062 AND `TextId`=20643) OR (`MenuId`=14288 AND `TextId`=20163) OR (`MenuId`=15059 AND `TextId`=20648) OR (`MenuId`=15061 AND `TextId`=20646) OR (`MenuId`=14914 AND `TextId`=20639) OR (`MenuId`=13821 AND `TextId`=19950) OR (`MenuId`=14326 AND `TextId`=20229) OR (`MenuId`=15076 AND `TextId`=20030) OR (`MenuId`=14915 AND `TextId`=20641) OR (`MenuId`=13864 AND `TextId`=20030) OR (`MenuId`=14304 AND `TextId`=20180) OR (`MenuId`=14305 AND `TextId`=20180) OR (`MenuId`=14325 AND `TextId`=20228) OR (`MenuId`=15060 AND `TextId`=20645) OR (`MenuId`=15058 AND `TextId`=20647) OR (`MenuId`=15057 AND `TextId`=21291) OR (`MenuId`=14597 AND `TextId`=20649) OR (`MenuId`=14891 AND `TextId`=21051) OR (`MenuId`=13761 AND `TextId`=19816) OR (`MenuId`=13760 AND `TextId`=19815) OR (`MenuId`=13759 AND `TextId`=19719) OR (`MenuId`=14270 AND `TextId`=20117) OR (`MenuId`=13732 AND `TextId`=19737) OR (`MenuId`=13723 AND `TextId`=19796) OR (`MenuId`=14640 AND `TextId`=20702) OR (`MenuId`=13745 AND `TextId`=19775) OR (`MenuId`=13745 AND `TextId`=19774) OR (`MenuId`=13665 AND `TextId`=19606) OR (`MenuId`=13664 AND `TextId`=19599) OR (`MenuId`=13665 AND `TextId`=19605) OR (`MenuId`=13689 AND `TextId`=19653) OR (`MenuId`=13690 AND `TextId`=19654) OR (`MenuId`=13689 AND `TextId`=19652) OR (`MenuId`=14039 AND `TextId`=20097) OR (`MenuId`=13689 AND `TextId`=19651) OR (`MenuId`=14648 AND `TextId`=20723) OR (`MenuId`=13713 AND `TextId`=19697) OR (`MenuId`=13714 AND `TextId`=19705) OR (`MenuId`=13497 AND `TextId`=19230) OR (`MenuId`=13460 AND `TextId`=19159) OR (`MenuId`=13446 AND `TextId`=19228) OR (`MenuId`=13440 AND `TextId`=19133) OR (`MenuId`=13492 AND `TextId`=19215) OR (`MenuId`=13493 AND `TextId`=19217) OR (`MenuId`=13494 AND `TextId`=19216) OR (`MenuId`=13487 AND `TextId`=19195) OR (`MenuId`=13455 AND `TextId`=19227) OR (`MenuId`=13497 AND `TextId`=19224) OR (`MenuId`=15139 AND `TextId`=21701) OR (`MenuId`=13455 AND `TextId`=19152) OR (`MenuId`=13441 AND `TextId`=19134) OR (`MenuId`=13441 AND `TextId`=19135) OR (`MenuId`=13639 AND `TextId`=19557) OR (`MenuId`=13607 AND `TextId`=19509) OR (`MenuId`=13611 AND `TextId`=19527) OR (`MenuId`=13513 AND `TextId`=19287) OR (`MenuId`=13537 AND `TextId`=19292) OR (`MenuId`=13535 AND `TextId`=19288) OR (`MenuId`=13513 AND `TextId`=19259) OR (`MenuId`=13468 AND `TextId`=19274) OR (`MenuId`=13468 AND `TextId`=19180) OR (`MenuId`=15092 AND `TextId`=21492) OR (`MenuId`=15091 AND `TextId`=21491) OR (`MenuId`=13454 AND `TextId`=19150) OR (`MenuId`=13446 AND `TextId`=19249) OR (`MenuId`=13446 AND `TextId`=19141) OR (`MenuId`=13189 AND `TextId`=18591) OR (`MenuId`=13488 AND `TextId`=19198) OR (`MenuId`=15716 AND `TextId`=22574) OR (`MenuId`=15720 AND `TextId`=22578) OR (`MenuId`=14923 AND `TextId`=21094) OR (`MenuId`=14916 AND `TextId`=21087) OR (`MenuId`=15714 AND `TextId`=22572) OR (`MenuId`=15715 AND `TextId`=22573) OR (`MenuId`=15717 AND `TextId`=22575) OR (`MenuId`=14917 AND `TextId`=21088) OR (`MenuId`=15722 AND `TextId`=22580) OR (`MenuId`=15721 AND `TextId`=22579) OR (`MenuId`=14924 AND `TextId`=21095) OR (`MenuId`=13717 AND `TextId`=19709) OR (`MenuId`=14310 AND `TextId`=20203) OR (`MenuId`=14328 AND `TextId`=20232) OR (`MenuId`=14334 AND `TextId`=20241) OR (`MenuId`=14333 AND `TextId`=20240) OR (`MenuId`=15046 AND `TextId`=21281) OR (`MenuId`=13454 AND `TextId`=19151) OR (`MenuId`=13498 AND `TextId`=19225) OR (`MenuId`=13496 AND `TextId`=19221) OR (`MenuId`=13495 AND `TextId`=19219) OR (`MenuId`=13491 AND `TextId`=19212) OR (`MenuId`=13499 AND `TextId`=19226) OR (`MenuId`=13455 AND `TextId`=19153) OR (`MenuId`=13519 AND `TextId`=19266) OR (`MenuId`=13384 AND `TextId`=19011) OR (`MenuId`=13419 AND `TextId`=19072) OR (`MenuId`=13351 AND `TextId`=19045) OR (`MenuId`=13404 AND `TextId`=19047) OR (`MenuId`=13403 AND `TextId`=19046) OR (`MenuId`=13350 AND `TextId`=21699) OR (`MenuId`=13349 AND `TextId`=21698) OR (`MenuId`=13387 AND `TextId`=19015) OR (`MenuId`=15141 AND `TextId`=21702) OR (`MenuId`=13351 AND `TextId`=19031) OR (`MenuId`=13354 AND `TextId`=18946) OR (`MenuId`=13353 AND `TextId`=18945) OR (`MenuId`=13355 AND `TextId`=18947) OR (`MenuId`=13353 AND `TextId`=18944) OR (`MenuId`=13387 AND `TextId`=19014) OR (`MenuId`=13387 AND `TextId`=19013) OR (`MenuId`=13350 AND `TextId`=18938) OR (`MenuId`=13349 AND `TextId`=18937) OR (`MenuId`=14050 AND `TextId`=20101) OR (`MenuId`=13351 AND `TextId`=18939) OR (`MenuId`=13536 AND `TextId`=19291) OR (`MenuId`=13333 AND `TextId`=18884) OR (`MenuId`=13333 AND `TextId`=18883) OR (`MenuId`=13334 AND `TextId`=18887) OR (`MenuId`=13334 AND `TextId`=18888) OR (`MenuId`=13339 AND `TextId`=18894) OR (`MenuId`=15130 AND `TextId`=21696) OR (`MenuId`=13850 AND `TextId`=20016) OR (`MenuId`=13850 AND `TextId`=18897) OR (`MenuId`=13600 AND `TextId`=19475) OR (`MenuId`=13332 AND `TextId`=18882) OR (`MenuId`=13601 AND `TextId`=19477) OR (`MenuId`=13593 AND `TextId`=19426) OR (`MenuId`=13338 AND `TextId`=18893) OR (`MenuId`=13602 AND `TextId`=19478) OR (`MenuId`=13853 AND `TextId`=18893) OR (`MenuId`=13578 AND `TextId`=19394) OR (`MenuId`=13597 AND `TextId`=19473) OR (`MenuId`=13594 AND `TextId`=19443) OR (`MenuId`=15047 AND `TextId`=21282) OR (`MenuId`=13409 AND `TextId`=19158) OR (`MenuId`=13445 AND `TextId`=19583) OR (`MenuId`=13653 AND `TextId`=19584) OR (`MenuId`=15156 AND `TextId`=21720) OR (`MenuId`=13663 AND `TextId`=19596) OR (`MenuId`=13662 AND `TextId`=19595) OR (`MenuId`=13661 AND `TextId`=19594) OR (`MenuId`=13660 AND `TextId`=19593) OR (`MenuId`=13659 AND `TextId`=19592) OR (`MenuId`=13658 AND `TextId`=19591) OR (`MenuId`=13657 AND `TextId`=19590) OR (`MenuId`=13656 AND `TextId`=19589) OR (`MenuId`=13655 AND `TextId`=19587) OR (`MenuId`=13654 AND `TextId`=19585) OR (`MenuId`=13642 AND `TextId`=19562) OR (`MenuId`=13475 AND `TextId`=19185) OR (`MenuId`=13476 AND `TextId`=19184) OR (`MenuId`=13485 AND `TextId`=19194) OR (`MenuId`=13484 AND `TextId`=19193) OR (`MenuId`=13483 AND `TextId`=19192) OR (`MenuId`=13482 AND `TextId`=19191) OR (`MenuId`=13481 AND `TextId`=19190) OR (`MenuId`=13480 AND `TextId`=19189) OR (`MenuId`=13479 AND `TextId`=19188) OR (`MenuId`=13477 AND `TextId`=19186) OR (`MenuId`=13478 AND `TextId`=19187) OR (`MenuId`=13567 AND `TextId`=19181) OR (`MenuId`=13469 AND `TextId`=19376) OR (`MenuId`=13445 AND `TextId`=19618) OR (`MenuId`=13640 AND `TextId`=19564) OR (`MenuId`=13641 AND `TextId`=19563) OR (`MenuId`=14403 AND `TextId`=20329) OR (`MenuId`=14425 AND `TextId`=20351) OR (`MenuId`=14430 AND `TextId`=20361) OR (`MenuId`=14572 AND `TextId`=20603) OR (`MenuId`=14426 AND `TextId`=20352) OR (`MenuId`=13582 AND `TextId`=19404) OR (`MenuId`=14427 AND `TextId`=20354) OR (`MenuId`=13584 AND `TextId`=19406) OR (`MenuId`=13583 AND `TextId`=19405) OR (`MenuId`=13585 AND `TextId`=19407) OR (`MenuId`=14379 AND `TextId`=20624) OR (`MenuId`=14585 AND `TextId`=20624) OR (`MenuId`=14418 AND `TextId`=20344) OR (`MenuId`=14422 AND `TextId`=20620) OR (`MenuId`=14416 AND `TextId`=20343) OR (`MenuId`=13596 AND `TextId`=19466) OR (`MenuId`=13608 AND `TextId`=19513) OR (`MenuId`=15610 AND `TextId`=22420) OR (`MenuId`=14581 AND `TextId`=20618) OR (`MenuId`=13595 AND `TextId`=19460) OR (`MenuId`=13609 AND `TextId`=19526) OR (`MenuId`=14417 AND `TextId`=20342) OR (`MenuId`=14584 AND `TextId`=20622) OR (`MenuId`=14583 AND `TextId`=20621) OR (`MenuId`=13445 AND `TextId`=19140) OR (`MenuId`=13442 AND `TextId`=19136) OR (`MenuId`=14423 AND `TextId`=20348) OR (`MenuId`=13409 AND `TextId`=19056) OR (`MenuId`=14424 AND `TextId`=20350) OR (`MenuId`=15579 AND `TextId`=22376) OR (`MenuId`=15597 AND `TextId`=22394) OR (`MenuId`=15596 AND `TextId`=22393) OR (`MenuId`=13343 AND `TextId`=18900) OR (`MenuId`=13342 AND `TextId`=18899) OR (`MenuId`=13336 AND `TextId`=18935) OR (`MenuId`=13342 AND `TextId`=18898) OR (`MenuId`=13344 AND `TextId`=18908) OR (`MenuId`=13336 AND `TextId`=18891) OR (`MenuId`=13327 AND `TextId`=18907) OR (`MenuId`=13327 AND `TextId`=18906) OR (`MenuId`=13300 AND `TextId`=18862) OR (`MenuId`=13315 AND `TextId`=18861) OR (`MenuId`=13315 AND `TextId`=18842) OR (`MenuId`=13300 AND `TextId`=18807) OR (`MenuId`=14890 AND `TextId`=18676) OR (`MenuId`=13327 AND `TextId`=18878) OR (`MenuId`=13740 AND `TextId`=19767) OR (`MenuId`=13279 AND `TextId`=21212) OR (`MenuId`=13279 AND `TextId`=21213) OR (`MenuId`=13750 AND `TextId`=19777) OR (`MenuId`=13751 AND `TextId`=19778) OR (`MenuId`=13276 AND `TextId`=21211) OR (`MenuId`=13742 AND `TextId`=19766) OR (`MenuId`=13741 AND `TextId`=19765) OR (`MenuId`=13270 AND `TextId`=18735) OR (`MenuId`=14383 AND `TextId`=20306) OR (`MenuId`=14315 AND `TextId`=21632) OR (`MenuId`=14363 AND `TextId`=20277) OR (`MenuId`=16471 AND `TextId`=23888) OR (`MenuId`=14330 AND `TextId`=20237) OR (`MenuId`=15605 AND `TextId`=22411) OR (`MenuId`=14936 AND `TextId`=21115) OR (`MenuId`=14934 AND `TextId`=21108) OR (`MenuId`=15114 AND `TextId`=21627) OR (`MenuId`=15113 AND `TextId`=21626) OR (`MenuId`=13885 AND `TextId`=20072) OR (`MenuId`=13244 AND `TextId`=18669) OR (`MenuId`=13243 AND `TextId`=18668) OR (`MenuId`=13253 AND `TextId`=18697) OR (`MenuId`=13230 AND `TextId`=18689) OR (`MenuId`=13230 AND `TextId`=18687) OR (`MenuId`=13230 AND `TextId`=18649) OR (`MenuId`=13230 AND `TextId`=18688) OR (`MenuId`=13230 AND `TextId`=18686) OR (`MenuId`=13237 AND `TextId`=18659) OR (`MenuId`=13242 AND `TextId`=18667) OR (`MenuId`=13242 AND `TextId`=20021) OR (`MenuId`=13251 AND `TextId`=18660) OR (`MenuId`=15001 AND `TextId`=21210) OR (`MenuId`=13416 AND `TextId`=19063) OR (`MenuId`=13415 AND `TextId`=19062) OR (`MenuId`=13418 AND `TextId`=19066) OR (`MenuId`=13417 AND `TextId`=19064) OR (`MenuId`=12950 AND `TextId`=18221) OR (`MenuId`=12943 AND `TextId`=18208) OR (`MenuId`=12940 AND `TextId`=18204) OR (`MenuId`=12015 AND `TextId`=16839) OR (`MenuId`=12009 AND `TextId`=16728) OR (`MenuId`=11690 AND `TextId`=16367) OR (`MenuId`=12438 AND `TextId`=17491) OR (`MenuId`=18637 AND `TextId`=27063) OR (`MenuId`=11950 AND `TextId`=16777) OR (`MenuId`=12234 AND `TextId`=17178) OR (`MenuId`=11773 AND `TextId`=17177) OR (`MenuId`=11692 AND `TextId`=16373) OR (`MenuId`=12930 AND `TextId`=18186) OR (`MenuId`=12938 AND `TextId`=18202) OR (`MenuId`=12482 AND `TextId`=17559) OR (`MenuId`=12231 AND `TextId`=17174) OR (`MenuId`=11423 AND `TextId`=15907) OR (`MenuId`=11305 AND `TextId`=15756) OR (`MenuId`=11421 AND `TextId`=15904) OR (`MenuId`=20916 AND `TextId`=31502) OR (`MenuId`=20920 AND `TextId`=31498) OR (`MenuId`=20917 AND `TextId`=17200) OR (`MenuId`=20922 AND `TextId`=31499) OR (`MenuId`=20919 AND `TextId`=31500) OR (`MenuId`=19861 AND `TextId`=29496) OR (`MenuId`=20486 AND `TextId`=30648) OR (`MenuId`=19930 AND `TextId`=29609) OR (`MenuId`=17030 AND `TextId`=24847) OR (`MenuId`=16856 AND `TextId`=24513) OR (`MenuId`=18712 AND `TextId`=27197) OR (`MenuId`=18418 AND `TextId`=26553) OR (`MenuId`=18337 AND `TextId`=26390) OR (`MenuId`=18417 AND `TextId`=26552) OR (`MenuId`=18336 AND `TextId`=26391) OR (`MenuId`=18226 AND `TextId`=26179) OR (`MenuId`=18225 AND `TextId`=26180) OR (`MenuId`=18328 AND `TextId`=26381) OR (`MenuId`=18511 AND `TextId`=26760) OR (`MenuId`=18258 AND `TextId`=26254) OR (`MenuId`=18257 AND `TextId`=26253) OR (`MenuId`=18949 AND `TextId`=27661) OR (`MenuId`=18582 AND `TextId`=26939) OR (`MenuId`=18582 AND `TextId`=26940) OR (`MenuId`=18387 AND `TextId`=26487) OR (`MenuId`=18948 AND `TextId`=27660) OR (`MenuId`=16242 AND `TextId`=23484) OR (`MenuId`=16549 AND `TextId`=24035) OR (`MenuId`=16551 AND `TextId`=24037) OR (`MenuId`=16543 AND `TextId`=24026) OR (`MenuId`=16545 AND `TextId`=24031) OR (`MenuId`=16663 AND `TextId`=24202) OR (`MenuId`=16550 AND `TextId`=24036) OR (`MenuId`=16667 AND `TextId`=24206) OR (`MenuId`=16661 AND `TextId`=24200) OR (`MenuId`=16660 AND `TextId`=24199) OR (`MenuId`=17533 AND `TextId`=24926) OR (`MenuId`=16024 AND `TextId`=23115) OR (`MenuId`=16023 AND `TextId`=23114) OR (`MenuId`=16110 AND `TextId`=23214) OR (`MenuId`=16940 AND `TextId`=24652) OR (`MenuId`=16942 AND `TextId`=24654) OR (`MenuId`=16136 AND `TextId`=23259) OR (`MenuId`=16424 AND `TextId`=23799) OR (`MenuId`=15997 AND `TextId`=23064) OR (`MenuId`=16442 AND `TextId`=23763) OR (`MenuId`=15997 AND `TextId`=23763) OR (`MenuId`=16395 AND `TextId`=23763) OR (`MenuId`=16396 AND `TextId`=23763) OR (`MenuId`=16134 AND `TextId`=23258) OR (`MenuId`=16144 AND `TextId`=23275) OR (`MenuId`=16144 AND `TextId`=23274) OR (`MenuId`=16144 AND `TextId`=23273) OR (`MenuId`=16144 AND `TextId`=23272) OR (`MenuId`=16979 AND `TextId`=24716) OR (`MenuId`=16016 AND `TextId`=23104) OR (`MenuId`=16014 AND `TextId`=23102) OR (`MenuId`=16015 AND `TextId`=23103) OR (`MenuId`=16375 AND `TextId`=23739) OR (`MenuId`=16017 AND `TextId`=23105) OR (`MenuId`=16012 AND `TextId`=23100) OR (`MenuId`=15979 AND `TextId`=23012) OR (`MenuId`=15860 AND `TextId`=23845) OR (`MenuId`=16454 AND `TextId`=23850) OR (`MenuId`=15262 AND `TextId`=21875) OR (`MenuId`=15174 AND `TextId`=21750) OR (`MenuId`=15336 AND `TextId`=22007) OR (`MenuId`=15338 AND `TextId`=22014) OR (`MenuId`=15259 AND `TextId`=21872) OR (`MenuId`=15258 AND `TextId`=21871) OR (`MenuId`=15212 AND `TextId`=21809) OR (`MenuId`=15303 AND `TextId`=21928) OR (`MenuId`=15302 AND `TextId`=21927) OR (`MenuId`=15764 AND `TextId`=22647) OR (`MenuId`=14955 AND `TextId`=19719) OR (`MenuId`=16509 AND `TextId`=23979) OR (`MenuId`=16370 AND `TextId`=23714) OR (`MenuId`=16364 AND `TextId`=23711) OR (`MenuId`=13829 AND `TextId`=19965) OR (`MenuId`=13829 AND `TextId`=20652) OR (`MenuId`=14357 AND `TextId`=20269) OR (`MenuId`=14362 AND `TextId`=20276) OR (`MenuId`=14615 AND `TextId`=20676) OR (`MenuId`=15545 AND `TextId`=22338) OR (`MenuId`=14409 AND `TextId`=20335) OR (`MenuId`=15967 AND `TextId`=22992) OR (`MenuId`=14582 AND `TextId`=20619) OR (`MenuId`=15958 AND `TextId`=22981) OR (`MenuId`=15152 AND `TextId`=933) OR (`MenuId`=14404 AND `TextId`=20330) OR (`MenuId`=14826 AND `TextId`=20986) OR (`MenuId`=14558 AND `TextId`=20579) OR (`MenuId`=14828 AND `TextId`=20988) OR (`MenuId`=14827 AND `TextId`=20987) OR (`MenuId`=14830 AND `TextId`=20990) OR (`MenuId`=10656 AND `TextId`=20943) OR (`MenuId`=15718 AND `TextId`=22576) OR (`MenuId`=14802 AND `TextId`=20947) OR (`MenuId`=14803 AND `TextId`=20948) OR (`MenuId`=14809 AND `TextId`=20959) OR (`MenuId`=15956 AND `TextId`=22974) OR (`MenuId`=14818 AND `TextId`=20970) OR (`MenuId`=14566 AND `TextId`=20589) OR (`MenuId`=14810 AND `TextId`=20960) OR (`MenuId`=14808 AND `TextId`=20957) OR (`MenuId`=14825 AND `TextId`=20985) OR (`MenuId`=14829 AND `TextId`=20989) OR (`MenuId`=15952 AND `TextId`=22968) OR (`MenuId`=14680 AND `TextId`=11714) OR (`MenuId`=14804 AND `TextId`=20949) OR (`MenuId`=14806 AND `TextId`=20950) OR (`MenuId`=14805 AND `TextId`=20951) OR (`MenuId`=14833 AND `TextId`=20993) OR (`MenuId`=14690 AND `TextId`=21000) OR (`MenuId`=14801 AND `TextId`=20946) OR (`MenuId`=13648 AND `TextId`=19608) OR (`MenuId`=15690 AND `TextId`=22539) OR (`MenuId`=15105 AND `TextId`=21615) OR (`MenuId`=15107 AND `TextId`=21614) OR (`MenuId`=15977 AND `TextId`=23008) OR (`MenuId`=15148 AND `TextId`=23007) OR (`MenuId`=14794 AND `TextId`=20917) OR (`MenuId`=14518 AND `TextId`=20527) OR (`MenuId`=14346 AND `TextId`=20255) OR (`MenuId`=14517 AND `TextId`=20528) OR (`MenuId`=14793 AND `TextId`=20916) OR (`MenuId`=14523 AND `TextId`=20534) OR (`MenuId`=14522 AND `TextId`=20532) OR (`MenuId`=14524 AND `TextId`=20533) OR (`MenuId`=13651 AND `TextId`=19580) OR (`MenuId`=14792 AND `TextId`=20918) OR (`MenuId`=14514 AND `TextId`=20524) OR (`MenuId`=14347 AND `TextId`=20256) OR (`MenuId`=14515 AND `TextId`=20525) OR (`MenuId`=14348 AND `TextId`=20257) OR (`MenuId`=14512 AND `TextId`=20519) OR (`MenuId`=14513 AND `TextId`=20520) OR (`MenuId`=14510 AND `TextId`=20517) OR (`MenuId`=14791 AND `TextId`=20915) OR (`MenuId`=14508 AND `TextId`=20515) OR (`MenuId`=14507 AND `TextId`=20514) OR (`MenuId`=14509 AND `TextId`=20516) OR (`MenuId`=14504 AND `TextId`=20511) OR (`MenuId`=14790 AND `TextId`=20914) OR (`MenuId`=14505 AND `TextId`=20512) OR (`MenuId`=14350 AND `TextId`=20259) OR (`MenuId`=14506 AND `TextId`=20513) OR (`MenuId`=14789 AND `TextId`=20912) OR (`MenuId`=14503 AND `TextId`=20510) OR (`MenuId`=14349 AND `TextId`=20258) OR (`MenuId`=14502 AND `TextId`=20509) OR (`MenuId`=14495 AND `TextId`=20502) OR (`MenuId`=14351 AND `TextId`=20260) OR (`MenuId`=14494 AND `TextId`=20501) OR (`MenuId`=14788 AND `TextId`=20921) OR (`MenuId`=14520 AND `TextId`=20531) OR (`MenuId`=14519 AND `TextId`=20529) OR (`MenuId`=14521 AND `TextId`=20530) OR (`MenuId`=14819 AND `TextId`=19719) OR (`MenuId`=14574 AND `TextId`=20605) OR (`MenuId`=14576 AND `TextId`=20607) OR (`MenuId`=14575 AND `TextId`=20606) OR (`MenuId`=14692 AND `TextId`=20843) OR (`MenuId`=14751 AND `TextId`=20844) OR (`MenuId`=14752 AND `TextId`=20845) OR (`MenuId`=14693 AND `TextId`=20821) OR (`MenuId`=14771 AND `TextId`=20865) OR (`MenuId`=14750 AND `TextId`=20841) OR (`MenuId`=14749 AND `TextId`=20840) OR (`MenuId`=14748 AND `TextId`=20839) OR (`MenuId`=14747 AND `TextId`=20838) OR (`MenuId`=14746 AND `TextId`=20837) OR (`MenuId`=14745 AND `TextId`=20836) OR (`MenuId`=14744 AND `TextId`=20835) OR (`MenuId`=14743 AND `TextId`=20834) OR (`MenuId`=14742 AND `TextId`=20833) OR (`MenuId`=14770 AND `TextId`=20864) OR (`MenuId`=14741 AND `TextId`=20832) OR (`MenuId`=14740 AND `TextId`=20831) OR (`MenuId`=14739 AND `TextId`=20830) OR (`MenuId`=14738 AND `TextId`=20829) OR (`MenuId`=14737 AND `TextId`=20828) OR (`MenuId`=14736 AND `TextId`=20827) OR (`MenuId`=14735 AND `TextId`=20825) OR (`MenuId`=14697 AND `TextId`=20826) OR (`MenuId`=14696 AND `TextId`=20824) OR (`MenuId`=14695 AND `TextId`=20823) OR (`MenuId`=14694 AND `TextId`=20822) OR (`MenuId`=14691 AND `TextId`=20820) OR (`MenuId`=14772 AND `TextId`=20908) OR (`MenuId`=14785 AND `TextId`=20914) OR (`MenuId`=14784 AND `TextId`=20917) OR (`MenuId`=14783 AND `TextId`=20915) OR (`MenuId`=14782 AND `TextId`=20921) OR (`MenuId`=14781 AND `TextId`=20916) OR (`MenuId`=14780 AND `TextId`=20918) OR (`MenuId`=14778 AND `TextId`=20919) OR (`MenuId`=14776 AND `TextId`=20912) OR (`MenuId`=14775 AND `TextId`=20911) OR (`MenuId`=14831 AND `TextId`=20991) OR (`MenuId`=14774 AND `TextId`=20910) OR (`MenuId`=14773 AND `TextId`=20909) OR (`MenuId`=14769 AND `TextId`=20846) OR (`MenuId`=14768 AND `TextId`=20862) OR (`MenuId`=14767 AND `TextId`=20861) OR (`MenuId`=14766 AND `TextId`=20860) OR (`MenuId`=14765 AND `TextId`=20859) OR (`MenuId`=14764 AND `TextId`=20858) OR (`MenuId`=14763 AND `TextId`=20857) OR (`MenuId`=14761 AND `TextId`=20856) OR (`MenuId`=14762 AND `TextId`=20855) OR (`MenuId`=14754 AND `TextId`=20848) OR (`MenuId`=14760 AND `TextId`=20854) OR (`MenuId`=14759 AND `TextId`=20853) OR (`MenuId`=14758 AND `TextId`=20852) OR (`MenuId`=14756 AND `TextId`=20851) OR (`MenuId`=14757 AND `TextId`=20850) OR (`MenuId`=14755 AND `TextId`=20849) OR (`MenuId`=14689 AND `TextId`=20819) OR (`MenuId`=14688 AND `TextId`=20818) OR (`MenuId`=14686 AND `TextId`=20816) OR (`MenuId`=14561 AND `TextId`=20583) OR (`MenuId`=15127 AND `TextId`=21694) OR (`MenuId`=14469 AND `TextId`=20412) OR (`MenuId`=15050 AND `TextId`=21285) OR (`MenuId`=14457 AND `TextId`=20398) OR (`MenuId`=14471 AND `TextId`=20414) OR (`MenuId`=15765 AND `TextId`=22648) OR (`MenuId`=14630 AND `TextId`=20691) OR (`MenuId`=14470 AND `TextId`=20413) OR (`MenuId`=14459 AND `TextId`=20400) OR (`MenuId`=14482 AND `TextId`=20425) OR (`MenuId`=13438 AND `TextId`=19128) OR (`MenuId`=13686 AND `TextId`=19636) OR (`MenuId`=13685 AND `TextId`=19634) OR (`MenuId`=13638 AND `TextId`=19974) OR (`MenuId`=13638 AND `TextId`=19556) OR (`MenuId`=13637 AND `TextId`=19555) OR (`MenuId`=13645 AND `TextId`=19571) OR (`MenuId`=13635 AND `TextId`=19552) OR (`MenuId`=13691 AND `TextId`=19656) OR (`MenuId`=13692 AND `TextId`=19655) OR (`MenuId`=13636 AND `TextId`=19554) OR (`MenuId`=13644 AND `TextId`=19568) OR (`MenuId`=13727 AND `TextId`=19724) OR (`MenuId`=13591 AND `TextId`=19414) OR (`MenuId`=13554 AND `TextId`=19342) OR (`MenuId`=13671 AND `TextId`=19616) OR (`MenuId`=13786 AND `TextId`=19870) OR (`MenuId`=13784 AND `TextId`=19868) OR (`MenuId`=13852 AND `TextId`=20018) OR (`MenuId`=13851 AND `TextId`=20017) OR (`MenuId`=15540 AND `TextId`=22331) OR (`MenuId`=14526 AND `TextId`=20536) OR (`MenuId`=14525 AND `TextId`=20535) OR (`MenuId`=14528 AND `TextId`=20538) OR (`MenuId`=14605 AND `TextId`=20663) OR (`MenuId`=13789 AND `TextId`=19876) OR (`MenuId`=13545 AND `TextId`=19330) OR (`MenuId`=13544 AND `TextId`=19325) OR (`MenuId`=13545 AND `TextId`=19328) OR (`MenuId`=13544 AND `TextId`=19323) OR (`MenuId`=13544 AND `TextId`=19324) OR (`MenuId`=14855 AND `TextId`=21033) OR (`MenuId`=14868 AND `TextId`=21026) OR (`MenuId`=14855 AND `TextId`=21015) OR (`MenuId`=14868 AND `TextId`=21024) OR (`MenuId`=13783 AND `TextId`=19915) OR (`MenuId`=13806 AND `TextId`=19908) OR (`MenuId`=13805 AND `TextId`=19904) OR (`MenuId`=13744 AND `TextId`=19769) OR (`MenuId`=13783 AND `TextId`=19867) OR (`MenuId`=13803 AND `TextId`=19894) OR (`MenuId`=13806 AND `TextId`=19909) OR (`MenuId`=14800 AND `TextId`=20941) OR (`MenuId`=15116 AND `TextId`=21631) OR (`MenuId`=14531 AND `TextId`=20548) OR (`MenuId`=14530 AND `TextId`=20547) OR (`MenuId`=14532 AND `TextId`=20539) OR (`MenuId`=14367 AND `TextId`=20282) OR (`MenuId`=14368 AND `TextId`=20283) OR (`MenuId`=13229 AND `TextId`=18648) OR (`MenuId`=13580 AND `TextId`=19398) OR (`MenuId`=14447 AND `TextId`=20385) OR (`MenuId`=14451 AND `TextId`=20390) OR (`MenuId`=14450 AND `TextId`=20388) OR (`MenuId`=13247 AND `TextId`=18663) OR (`MenuId`=13067 AND `TextId`=19872) OR (`MenuId`=13067 AND `TextId`=19873) OR (`MenuId`=13067 AND `TextId`=18351) OR (`MenuId`=13561 AND `TextId`=19355) OR (`MenuId`=13104 AND `TextId`=18409) OR (`MenuId`=13561 AND `TextId`=19354) OR (`MenuId`=13074 AND `TextId`=18360) OR (`MenuId`=13044 AND `TextId`=18319) OR (`MenuId`=13104 AND `TextId`=18408) OR (`MenuId`=14428 AND `TextId`=20353) OR (`MenuId`=13646 AND `TextId`=19573) OR (`MenuId`=14429 AND `TextId`=20360) OR (`MenuId`=14381 AND `TextId`=20278) OR (`MenuId`=14364 AND `TextId`=20278) OR (`MenuId`=13606 AND `TextId`=19331) OR (`MenuId`=13592 AND `TextId`=19415) OR (`MenuId`=13579 AND `TextId`=19396) OR (`MenuId`=13605 AND `TextId`=19472) OR (`MenuId`=13581 AND `TextId`=19400) OR (`MenuId`=13228 AND `TextId`=19308) OR (`MenuId`=13266 AND `TextId`=19309) OR (`MenuId`=13250 AND `TextId`=19306) OR (`MenuId`=13122 AND `TextId`=18460) OR (`MenuId`=13509 AND `TextId`=19254) OR (`MenuId`=13281 AND `TextId`=18777) OR (`MenuId`=13605 AND `TextId`=18718) OR (`MenuId`=13324 AND `TextId`=18873) OR (`MenuId`=13370 AND `TextId`=18970) OR (`MenuId`=13558 AND `TextId`=19345) OR (`MenuId`=13302 AND `TextId`=18875) OR (`MenuId`=13304 AND `TextId`=18814) OR (`MenuId`=13302 AND `TextId`=18811) OR (`MenuId`=13323 AND `TextId`=18868) OR (`MenuId`=13323 AND `TextId`=18869) OR (`MenuId`=13325 AND `TextId`=18874) OR (`MenuId`=13303 AND `TextId`=18813) OR (`MenuId`=13303 AND `TextId`=18812) OR (`MenuId`=13324 AND `TextId`=18876) OR (`MenuId`=13372 AND `TextId`=18976) OR (`MenuId`=13371 AND `TextId`=18973) OR (`MenuId`=13340 AND `TextId`=18895) OR (`MenuId`=13881 AND `TextId`=20066) OR (`MenuId`=13368 AND `TextId`=18969) OR (`MenuId`=13550 AND `TextId`=19336) OR (`MenuId`=13548 AND `TextId`=19334) OR (`MenuId`=13551 AND `TextId`=19337) OR (`MenuId`=13553 AND `TextId`=19341) OR (`MenuId`=13549 AND `TextId`=19335) OR (`MenuId`=13557 AND `TextId`=19338) OR (`MenuId`=14941 AND `TextId`=21121) OR (`MenuId`=13434 AND `TextId`=19111) OR (`MenuId`=13396 AND `TextId`=19025) OR (`MenuId`=13401 AND `TextId`=19040) OR (`MenuId`=14445 AND `TextId`=20383) OR (`MenuId`=14446 AND `TextId`=20384) OR (`MenuId`=13100 AND `TextId`=18397) OR (`MenuId`=13103 AND `TextId`=18405) OR (`MenuId`=15123 AND `TextId`=21653) OR (`MenuId`=13058 AND `TextId`=18337) OR (`MenuId`=13054 AND `TextId`=18333) OR (`MenuId`=13057 AND `TextId`=18336) OR (`MenuId`=13059 AND `TextId`=18338) OR (`MenuId`=13072 AND `TextId`=18358) OR (`MenuId`=13070 AND `TextId`=18356) OR (`MenuId`=13105 AND `TextId`=18411) OR (`MenuId`=13101 AND `TextId`=18398) OR (`MenuId`=13106 AND `TextId`=18412) OR (`MenuId`=13572 AND `TextId`=19386) OR (`MenuId`=13157 AND `TextId`=19372) OR (`MenuId`=13564 AND `TextId`=19367) OR (`MenuId`=13564 AND `TextId`=19891) OR (`MenuId`=13563 AND `TextId`=19365) OR (`MenuId`=13565 AND `TextId`=19369) OR (`MenuId`=13564 AND `TextId`=19366) OR (`MenuId`=13563 AND `TextId`=19364) OR (`MenuId`=14624 AND `TextId`=20685) OR (`MenuId`=13563 AND `TextId`=19362) OR (`MenuId`=14443 AND `TextId`=20376) OR (`MenuId`=14620 AND `TextId`=20681) OR (`MenuId`=14442 AND `TextId`=20375) OR (`MenuId`=14649 AND `TextId`=19889) OR (`MenuId`=14626 AND `TextId`=20687) OR (`MenuId`=14625 AND `TextId`=20686) OR (`MenuId`=13226 AND `TextId`=18643) OR (`MenuId`=13225 AND `TextId`=18646) OR (`MenuId`=13227 AND `TextId`=18644) OR (`MenuId`=13185 AND `TextId`=18585) OR (`MenuId`=13432 AND `TextId`=19097) OR (`MenuId`=13430 AND `TextId`=19095) OR (`MenuId`=13422 AND `TextId`=19077) OR (`MenuId`=13291 AND `TextId`=18794) OR (`MenuId`=13808 AND `TextId`=19912) OR (`MenuId`=13433 AND `TextId`=19098) OR (`MenuId`=14653 AND `TextId`=20727) OR (`MenuId`=13427 AND `TextId`=19091) OR (`MenuId`=13397 AND `TextId`=19108) OR (`MenuId`=13429 AND `TextId`=19094) OR (`MenuId`=13431 AND `TextId`=19096) OR (`MenuId`=13286 AND `TextId`=18789) OR (`MenuId`=13525 AND `TextId`=19273) OR (`MenuId`=13530 AND `TextId`=20212) OR (`MenuId`=13132 AND `TextId`=18473) OR (`MenuId`=13137 AND `TextId`=18478) OR (`MenuId`=13110 AND `TextId`=18523) OR (`MenuId`=13109 AND `TextId`=18422) OR (`MenuId`=13132 AND `TextId`=18825) OR (`MenuId`=13129 AND `TextId`=18470) OR (`MenuId`=13150 AND `TextId`=18424) OR (`MenuId`=13208 AND `TextId`=18614) OR (`MenuId`=13552 AND `TextId`=19339) OR (`MenuId`=15045 AND `TextId`=21280) OR (`MenuId`=13288 AND `TextId`=18792) OR (`MenuId`=13547 AND `TextId`=19332) OR (`MenuId`=14312 AND `TextId`=20207) OR (`MenuId`=13296 AND `TextId`=20183) OR (`MenuId`=13297 AND `TextId`=18804) OR (`MenuId`=13299 AND `TextId`=18806) OR (`MenuId`=13298 AND `TextId`=18805) OR (`MenuId`=13374 AND `TextId`=20209) OR (`MenuId`=13283 AND `TextId`=18786) OR (`MenuId`=13782 AND `TextId`=19863) OR (`MenuId`=13284 AND `TextId`=18787) OR (`MenuId`=14628 AND `TextId`=20689) OR (`MenuId`=13530 AND `TextId`=19277) OR (`MenuId`=14309 AND `TextId`=20199) OR (`MenuId`=13286 AND `TextId`=20181) OR (`MenuId`=13538 AND `TextId`=19293) OR (`MenuId`=13254 AND `TextId`=18702) OR (`MenuId`=13255 AND `TextId`=18703) OR (`MenuId`=13256 AND `TextId`=18704) OR (`MenuId`=13236 AND `TextId`=18577) OR (`MenuId`=13531 AND `TextId`=18577) OR (`MenuId`=14402 AND `TextId`=20328) OR (`MenuId`=14401 AND `TextId`=20327) OR (`MenuId`=14280 AND `TextId`=20127) OR (`MenuId`=14410 AND `TextId`=20336) OR (`MenuId`=13250 AND `TextId`=19305) OR (`MenuId`=13541 AND `TextId`=19311) OR (`MenuId`=13266 AND `TextId`=18721) OR (`MenuId`=13272 AND `TextId`=18737) OR (`MenuId`=13274 AND `TextId`=18739) OR (`MenuId`=13273 AND `TextId`=18738) OR (`MenuId`=13271 AND `TextId`=18736) OR (`MenuId`=13265 AND `TextId`=18720) OR (`MenuId`=13119 AND `TextId`=18453) OR (`MenuId`=13130 AND `TextId`=18471) OR (`MenuId`=13116 AND `TextId`=18450) OR (`MenuId`=13228 AND `TextId`=19307) OR (`MenuId`=13128 AND `TextId`=18466) OR (`MenuId`=13115 AND `TextId`=18447) OR (`MenuId`=13265 AND `TextId`=18718) OR (`MenuId`=13250 AND `TextId`=19280) OR (`MenuId`=13250 AND `TextId`=18684) OR (`MenuId`=13116 AND `TextId`=18679) OR (`MenuId`=13228 AND `TextId`=18647) OR (`MenuId`=13510 AND `TextId`=19255) OR (`MenuId`=13509 AND `TextId`=19924) OR (`MenuId`=13266 AND `TextId`=18722) OR (`MenuId`=13122 AND `TextId`=18677) OR (`MenuId`=13809 AND `TextId`=19913) OR (`MenuId`=13541 AND `TextId`=19310) OR (`MenuId`=13274 AND `TextId`=18741) OR (`MenuId`=13272 AND `TextId`=18741) OR (`MenuId`=13502 AND `TextId`=19235) OR (`MenuId`=13502 AND `TextId`=19237) OR (`MenuId`=13503 AND `TextId`=19238) OR (`MenuId`=13502 AND `TextId`=19241) OR (`MenuId`=13117 AND `TextId`=18451) OR (`MenuId`=15112 AND `TextId`=21624) OR (`MenuId`=14971 AND `TextId`=21622) OR (`MenuId`=13518 AND `TextId`=19264) OR (`MenuId`=13313 AND `TextId`=18838) OR (`MenuId`=14990 AND `TextId`=21266) OR (`MenuId`=13312 AND `TextId`=18835) OR (`MenuId`=15112 AND `TextId`=21623) OR (`MenuId`=14943 AND `TextId`=21124) OR (`MenuId`=14942 AND `TextId`=21123) OR (`MenuId`=14921 AND `TextId`=21092) OR (`MenuId`=14920 AND `TextId`=21091) OR (`MenuId`=14919 AND `TextId`=21090) OR (`MenuId`=14918 AND `TextId`=21089) OR (`MenuId`=14911 AND `TextId`=21086) OR (`MenuId`=14912 AND `TextId`=21085) OR (`MenuId`=14913 AND `TextId`=21084) OR (`MenuId`=15110 AND `TextId`=21619) OR (`MenuId`=14935 AND `TextId`=21114) OR (`MenuId`=14932 AND `TextId`=21106) OR (`MenuId`=15099 AND `TextId`=21500) OR (`MenuId`=15100 AND `TextId`=21501) OR (`MenuId`=14926 AND `TextId`=21097) OR (`MenuId`=15098 AND `TextId`=21499) OR (`MenuId`=14990 AND `TextId`=21203) OR (`MenuId`=14990 AND `TextId`=21190) OR (`MenuId`=14971 AND `TextId`=21617) OR (`MenuId`=14971 AND `TextId`=21166) OR (`MenuId`=15111 AND `TextId`=21620) OR (`MenuId`=12134 AND `TextId`=17045) OR (`MenuId`=12133 AND `TextId`=17042) OR (`MenuId`=12154 AND `TextId`=17089) OR (`MenuId`=12098 AND `TextId`=16986) OR (`MenuId`=12651 AND `TextId`=17799) OR (`MenuId`=12083 AND `TextId`=16959) OR (`MenuId`=12066 AND `TextId`=16923) OR (`MenuId`=12060 AND `TextId`=16908) OR (`MenuId`=12253 AND `TextId`=15104) OR (`MenuId`=12303 AND `TextId`=17296) OR (`MenuId`=12070 AND `TextId`=16938) OR (`MenuId`=13246 AND `TextId`=18672) OR (`MenuId`=13248 AND `TextId`=18678) OR (`MenuId`=13160 AND `TextId`=18544) OR (`MenuId`=12021 AND `TextId`=16847) OR (`MenuId`=12020 AND `TextId`=16846) OR (`MenuId`=12465 AND `TextId`=17534) OR (`MenuId`=12459 AND `TextId`=17521) OR (`MenuId`=12451 AND `TextId`=17513) OR (`MenuId`=12457 AND `TextId`=17518) OR (`MenuId`=12456 AND `TextId`=17517) OR (`MenuId`=12455 AND `TextId`=17516) OR (`MenuId`=12427 AND `TextId`=17472) OR (`MenuId`=12379 AND `TextId`=17399) OR (`MenuId`=12425 AND `TextId`=17468) OR (`MenuId`=12465 AND `TextId`=17533) OR (`MenuId`=12480 AND `TextId`=17557) OR (`MenuId`=12425 AND `TextId`=17467) OR (`MenuId`=12409 AND `TextId`=17443) OR (`MenuId`=12548 AND `TextId`=17626) OR (`MenuId`=15065 AND `TextId`=21295) OR (`MenuId`=11920 AND `TextId`=16736) OR (`MenuId`=12003 AND `TextId`=16825) OR (`MenuId`=12446 AND `TextId`=17503) OR (`MenuId`=12445 AND `TextId`=17501) OR (`MenuId`=12441 AND `TextId`=17496) OR (`MenuId`=12402 AND `TextId`=17431) OR (`MenuId`=12426 AND `TextId`=17469) OR (`MenuId`=12499 AND `TextId`=7727) OR (`MenuId`=12591 AND `TextId`=17710) OR (`MenuId`=12405 AND `TextId`=17434) OR (`MenuId`=12403 AND `TextId`=17432) OR (`MenuId`=12368 AND `TextId`=17372) OR (`MenuId`=12364 AND `TextId`=17368) OR (`MenuId`=12366 AND `TextId`=17370) OR (`MenuId`=12367 AND `TextId`=17371) OR (`MenuId`=12365 AND `TextId`=17369) OR (`MenuId`=12355 AND `TextId`=17360) OR (`MenuId`=12354 AND `TextId`=17359) OR (`MenuId`=12316 AND `TextId`=17311) OR (`MenuId`=12315 AND `TextId`=17310) OR (`MenuId`=12314 AND `TextId`=17309) OR (`MenuId`=12287 AND `TextId`=17255) OR (`MenuId`=12286 AND `TextId`=17254) OR (`MenuId`=12285 AND `TextId`=17253) OR (`MenuId`=12284 AND `TextId`=17252) OR (`MenuId`=12291 AND `TextId`=17259) OR (`MenuId`=12290 AND `TextId`=17258) OR (`MenuId`=12289 AND `TextId`=17257) OR (`MenuId`=12288 AND `TextId`=17256) OR (`MenuId`=12319 AND `TextId`=17314) OR (`MenuId`=12318 AND `TextId`=17313) OR (`MenuId`=12317 AND `TextId`=17312) OR (`MenuId`=12320 AND `TextId`=17315) OR (`MenuId`=12313 AND `TextId`=17308) OR (`MenuId`=12312 AND `TextId`=17307) OR (`MenuId`=12310 AND `TextId`=17305) OR (`MenuId`=12213 AND `TextId`=17192) OR (`MenuId`=12238 AND `TextId`=17189) OR (`MenuId`=12038 AND `TextId`=16868) OR (`MenuId`=11852 AND `TextId`=16614) OR (`MenuId`=11633 AND `TextId`=16246) OR (`MenuId`=11607 AND `TextId`=16202) OR (`MenuId`=11535 AND `TextId`=16105) OR (`MenuId`=11630 AND `TextId`=16243) OR (`MenuId`=11634 AND `TextId`=16247) OR (`MenuId`=11574 AND `TextId`=16164) OR (`MenuId`=11582 AND `TextId`=16172) OR (`MenuId`=11581 AND `TextId`=16171) OR (`MenuId`=11580 AND `TextId`=16170) OR (`MenuId`=11579 AND `TextId`=16169) OR (`MenuId`=11578 AND `TextId`=16168) OR (`MenuId`=11577 AND `TextId`=16167) OR (`MenuId`=11576 AND `TextId`=16166) OR (`MenuId`=11575 AND `TextId`=16165) OR (`MenuId`=11594 AND `TextId`=16189) OR (`MenuId`=11592 AND `TextId`=16187) OR (`MenuId`=11591 AND `TextId`=16186) OR (`MenuId`=11590 AND `TextId`=16185) OR (`MenuId`=11589 AND `TextId`=16184) OR (`MenuId`=11588 AND `TextId`=16183) OR (`MenuId`=11593 AND `TextId`=16182) OR (`MenuId`=11586 AND `TextId`=16188) OR (`MenuId`=11627 AND `TextId`=16239) OR (`MenuId`=11572 AND `TextId`=16149) OR (`MenuId`=11571 AND `TextId`=16147) OR (`MenuId`=11477 AND `TextId`=16014) OR (`MenuId`=11515 AND `TextId`=16069) OR (`MenuId`=11516 AND `TextId`=16070) OR (`MenuId`=11517 AND `TextId`=16071) OR (`MenuId`=11481 AND `TextId`=16019) OR (`MenuId`=11849 AND `TextId`=16610) OR (`MenuId`=12603 AND `TextId`=17741) OR (`MenuId`=12604 AND `TextId`=17742) OR (`MenuId`=11474 AND `TextId`=16008) OR (`MenuId`=11647 AND `TextId`=16270) OR (`MenuId`=11525 AND `TextId`=16084) OR (`MenuId`=11598 AND `TextId`=16193) OR (`MenuId`=11599 AND `TextId`=16194) OR (`MenuId`=11605 AND `TextId`=16198) OR (`MenuId`=11601 AND `TextId`=16195) OR (`MenuId`=11600 AND `TextId`=16196) OR (`MenuId`=11400 AND `TextId`=15880) OR (`MenuId`=11399 AND `TextId`=15878) OR (`MenuId`=11344 AND `TextId`=15802) OR (`MenuId`=11352 AND `TextId`=15818) OR (`MenuId`=11350 AND `TextId`=15820) OR (`MenuId`=11351 AND `TextId`=15819) OR (`MenuId`=11538 AND `TextId`=16108) OR (`MenuId`=11553 AND `TextId`=16122) OR (`MenuId`=11554 AND `TextId`=16125) OR (`MenuId`=12370 AND `TextId`=17374) OR (`MenuId`=11851 AND `TextId`=16613) OR (`MenuId`=11608 AND `TextId`=16203) OR (`MenuId`=17546 AND `TextId`=24884) OR (`MenuId`=17557 AND `TextId`=25291) OR (`MenuId`=17104 AND `TextId`=25148) OR (`MenuId`=17987 AND `TextId`=25930) OR (`MenuId`=16163 AND `TextId`=23341) OR (`MenuId`=16343 AND `TextId`=23662) OR (`MenuId`=16345 AND `TextId`=23664) OR (`MenuId`=16727 AND `TextId`=24322) OR (`MenuId`=16956 AND `TextId`=24672) OR (`MenuId`=16955 AND `TextId`=24670) OR (`MenuId`=16954 AND `TextId`=24669) OR (`MenuId`=16665 AND `TextId`=24204) OR (`MenuId`=16664 AND `TextId`=24203) OR (`MenuId`=16662 AND `TextId`=24201) OR (`MenuId`=16950 AND `TextId`=24664) OR (`MenuId`=17106 AND `TextId`=25150) OR (`MenuId`=16619 AND `TextId`=24143) OR (`MenuId`=16618 AND `TextId`=24142) OR (`MenuId`=16717 AND `TextId`=24294) OR (`MenuId`=16716 AND `TextId`=24293) OR (`MenuId`=16793 AND `TextId`=24415) OR (`MenuId`=16791 AND `TextId`=24417) OR (`MenuId`=16792 AND `TextId`=24416) OR (`MenuId`=16608 AND `TextId`=24129) OR (`MenuId`=16329 AND `TextId`=23643) OR (`MenuId`=18867 AND `TextId`=27478) OR (`MenuId`=16599 AND `TextId`=24103) OR (`MenuId`=16607 AND `TextId`=24128) OR (`MenuId`=16605 AND `TextId`=24125) OR (`MenuId`=16777 AND `TextId`=25433) OR (`MenuId`=17203 AND `TextId`=25434) OR (`MenuId`=16686 AND `TextId`=24237) OR (`MenuId`=16700 AND `TextId`=24269) OR (`MenuId`=16699 AND `TextId`=24268) OR (`MenuId`=16698 AND `TextId`=24267) OR (`MenuId`=16562 AND `TextId`=24057) OR (`MenuId`=17021 AND `TextId`=24833) OR (`MenuId`=16895 AND `TextId`=24573) OR (`MenuId`=16542 AND `TextId`=24025) OR (`MenuId`=16538 AND `TextId`=24021) OR (`MenuId`=16539 AND `TextId`=24022) OR (`MenuId`=16562 AND `TextId`=24059) OR (`MenuId`=16523 AND `TextId`=24002) OR (`MenuId`=18538 AND `TextId`=26811) OR (`MenuId`=18486 AND `TextId`=26743) OR (`MenuId`=18189 AND `TextId`=7778) OR (`MenuId`=16762 AND `TextId`=24355) OR (`MenuId`=16849 AND `TextId`=24500) OR (`MenuId`=16703 AND `TextId`=24288) OR (`MenuId`=17037 AND `TextId`=24893) OR (`MenuId`=16515 AND `TextId`=23991) OR (`MenuId`=17091 AND `TextId`=25121) OR (`MenuId`=16770 AND `TextId`=24369) OR (`MenuId`=17246 AND `TextId`=25520) OR (`MenuId`=16822 AND `TextId`=24456) OR (`MenuId`=16822 AND `TextId`=24458) OR (`MenuId`=16640 AND `TextId`=25241) OR (`MenuId`=16737 AND `TextId`=24337) OR (`MenuId`=16651 AND `TextId`=24187) OR (`MenuId`=16946 AND `TextId`=24656) OR (`MenuId`=16502 AND `TextId`=23966) OR (`MenuId`=16876 AND `TextId`=24540) OR (`MenuId`=16978 AND `TextId`=24715) OR (`MenuId`=16977 AND `TextId`=24714) OR (`MenuId`=17282 AND `TextId`=25592) OR (`MenuId`=16854 AND `TextId`=24510) OR (`MenuId`=16817 AND `TextId`=24451) OR (`MenuId`=16652 AND `TextId`=24188) OR (`MenuId`=16860 AND `TextId`=24519);
INSERT INTO `gossip_menu` (`MenuId`, `TextId`, `VerifiedBuild`) VALUES
(18491, 26718, 27602), -- 90177 (Exarch Yrel)
(18486, 26710, 27602), -- 95002 (Yanas Seastrike)
(18326, 26371, 27602), -- 90179 (Exarch Maladaar)
(18488, 26713, 27602), -- 93812 (Salty Jorren)
(18542, 26820, 27602), -- 93822 (Merreck Vonder)
(17051, 24993, 27602), -- 85839 (Sparz Boltwist)
(16872, 24532, 27602), -- 84248 (Justin Timberlord)
(16707, 24275, 27602), -- 81074 (Rangari Rajess)
(16877, 24541, 27602), -- 84509 (Skytalon Kuris)
(16718, 25242, 27602), -- 81770 (Reshad)
(16283, 23554, 27602), -- 76839 (Gotuun)
(16597, 7778, 27602), -- 81103 (Dungar Longdrink)
(17231, 25502, 27602), -- 88025 (Mylune)
(16897, 24584, 27602), -- 84947 (Lysa Serion)
(17055, 20298, 27602), -- 77354 (Ayada the White)
(17431, 25004, 27602), -- 77778 (Kaylie Macdonald)
(16864, 20298, 27602), -- 77382 (Christopher Macdonald)
(18201, 24624, 27602), -- 90381 (Tune-O-Tron 5000)
(18292, 26305, 27602), -- 91589 (Fix "Smallie" Biggswrench)
(18268, 26327, 27602), -- 91589 (Fix "Smallie" Biggswrench)
(16811, 24440, 27602), -- 79953 (Lieutenant Thorn)
(16514, 23987, 27602), -- 80595 (Kalandrios)
(16595, 24097, 27602), -- 231838
(16585, 24088, 27602), -- 81412 (Vindicator Yrel)
(16592, 24095, 27602), -- 81419 (Thrall)
(16781, 24401, 27602), -- 81424 (Draka)
(16588, 24091, 27602), -- 81415 (Durotan)
(16780, 24400, 27602), -- 81421 (Cordana Felsong)
(16779, 24397, 27602), -- 81420 (Archmage Khadgar)
(16783, 24402, 27602), -- 81425 (Rangari D'kaan)
(16594, 24096, 27602), -- 81423 (Aggra)
(16829, 24465, 27602), -- 83407 (Vindicator Yrel)
(16825, 24461, 27602), -- 83407 (Vindicator Yrel)
(16823, 24459, 27602), -- 81405 (Rangari D'kaan)
(16586, 24089, 27602), -- 81404 (Vindicator Yrel)
(16802, 24432, 27602), -- 81405 (Rangari D'kaan)
(16423, 23871, 27602), -- 79674 (Thaelin Darkanvil)
(16422, 23874, 27602), -- 79576 (Rangari D'kaan)
(16902, 24589, 27602), -- 84632 (Marybelle Walsh)
(17317, 25715, 27602), -- 88668 (Joz Navarix)
(17984, 25930, 27602), -- 89230 (Ancient Waygate Protector)
(17272, 25562, 27602), -- 87311 (Kharg)
(17266, 25551, 27602), -- 88139 (Olgor)
(17418, 25882, 27602), -- 76508 (Dizzy Sparkshift)
(16873, 24536, 27602), -- 84459 (Rangari Saardar)
(17253, 25528, 27602), -- 87393 (Sallee Silverclamp)
(17249, 25524, 27602), -- 87706 (Gazmolf Futzwangler)
(17257, 25532, 27602), -- 87397 (Twixnee Boltgear)
(17251, 25526, 27602), -- 88042 (Bozzil Boomcrank)
(16894, 24572, 27602), -- 84783 (Gurgthock)
(17042, 24953, 27602), -- 84784 (Wodin the Troll-Servant)
(16794, 24418, 27602), -- 83888 (Mister Knuckles)
(16537, 24019, 27602), -- 81039 (Vindicator Yrel)
(16548, 24034, 27602), -- 81123 (Captain "Victorious" Chong)
(16544, 24030, 27602), -- 81097 (Lieutenant K. K. Lee)
(16001, 24028, 27602), -- 81086 (Uruk Foecleaver)
(16544, 24029, 27602), -- 81097 (Lieutenant K. K. Lee)
(18287, 25004, 27602), -- 91582 (Apprentice Var'nath)
(16916, 24619, 27602), -- 78564 (Sergeant Crowler)
(16452, 23849, 27602), -- 80006 (Caregiver Felaani)
(16632, 24161, 27602), -- 80866 (Dahaka)
(16631, 24160, 27602), -- 80864 (Gar'rok)
(16771, 24378, 27602), -- 233263
(16659, 24198, 27602), -- 82181 (Vindicator Nobundo)
(16656, 24194, 27602), -- 82179 (Vindicator Nobundo)
(16728, 24326, 27602), -- 82844 (Gixmo Moneycash)
(16653, 24190, 27602), -- 82138 (Vindicator Nobundo)
(16513, 23986, 27602), -- 80593 (Incineratus)
(16492, 23944, 27602), -- 80434 (Gar'rok)
(16494, 23953, 27602), -- 80483 (Challe)
(16511, 23983, 27602), -- 80594 (Aborius)
(16732, 24328, 27602), -- 233235
(16903, 24590, 27602), -- 84861 (Dr. Hadley Ricard)
(16904, 24591, 27602), -- 84633 (Dr. Hadley Ricard)
(17293, 25634, 27602), -- 88500 (Murgok)
(17357, 25809, 27602), -- 88811 (Frightened Spirit)
(16666, 24205, 27602), -- 82163 (Hemet Nesingwary)
(16481, 23912, 27602), -- 80319 (Lantresor of the Blade)
(16606, 24124, 27602), -- 79282 (Rangari Eleena)
(16467, 23920, 27602), -- 79201 (Gazmolf Futzwangler)
(16466, 23882, 27602), -- 82658 (Trixi Leroux)
(16414, 23779, 27602), -- 79188 (Dexyl Deadblade)
(16416, 23783, 27602), -- 79189 (Guzrug the Tiny)
(16457, 23862, 27602), -- 79310 (Pyxni Pennypocket)
(16437, 23829, 27602), -- 79899 (Bazwix)
(16569, 24066, 27602), -- 81249 (Amma Stouthearth)
(16570, 24067, 27602), -- 81253 (Tradesman Portanuus)
(16456, 23861, 27602), -- 79312 (Greezlex Fizzpinch)
(16654, 24191, 27602), -- 82094 (Rangari Laara)
(16695, 24256, 27602), -- 82599 (Fallen Adventurer)
(16483, 23883, 27602), -- 79201 (Gazmolf Futzwangler)
(16837, 24480, 27602), -- 82746 (Abu'gar)
(16704, 24273, 27602), -- 80184 (Gabby Goldsnap)
(18167, 26094, 27602), -- 89702 (Lytah)
(17322, 25764, 27602), -- 84634 (Gellhorn)
(16506, 23973, 27602), -- 79954 (Hansel Heavyhands)
(16423, 23796, 27602), -- 79674 (Thaelin Darkanvil)
(16422, 23795, 27602), -- 79576 (Rangari D'kaan)
(16426, 23803, 27602), -- 79722 (Rangari Ogir)
(16427, 23804, 27602), -- 79743 (Vindicator Mo'mor)
(16722, 24305, 27602), -- 79761 (Arbiter Khan)
(16721, 24303, 27602), -- 79761 (Arbiter Khan)
(16668, 24207, 27602), -- 82252 (Captain Washburn)
(16697, 24266, 27602), -- 82640 (Explorer Lesko)
(16798, 24426, 27602), -- 83880 (Aspiring Wolfrider)
(16650, 24186, 27602), -- 82065 (Bryan Finn)
(16742, 24343, 27602), -- 83463 (Dusk-Seer Irizzar)
(16875, 24539, 27602), -- 84498 (Skytalon Meshaal)
(16640, 24169, 27602), -- 80153 (Shadow-Sage Iskar)
(16718, 24296, 27602), -- 81770 (Reshad)
(17296, 25638, 27602), -- 81929 (Lieutenant Willem)
(16696, 24261, 27602), -- 84450 (Sergeant Growlblade)
(17275, 25567, 27602), -- 88229 (Jacob Anders)
(16819, 24453, 27602), -- 82677 (Laborer)
(16831, 24467, 27602), -- 84119 (Gareth)
(16832, 24468, 27602), -- 84134 (Elria Willowfall)
(17043, 24954, 27602), -- 86386 (Kuro'ak)
(17201, 25426, 27602), -- 87775 (Ruuan the Seer)
(16718, 24295, 27602), -- 81770 (Reshad)
(17985, 25930, 27602), -- 89232 (Ancient Waygate Protector)
(17107, 25151, 27602), -- 82621 (Reshad)
(16476, 23905, 27602), -- 79890 (Ornekka)
(16476, 23904, 27602), -- 79890 (Ornekka)
(16575, 24076, 27602), -- 79519 (Reshad)
(16575, 24075, 27602), -- 79519 (Reshad)
(16684, 24232, 27602), -- 82467 (Krixel Pinchwhistle)
(16596, 24099, 27602), -- 81443 (Krixel Pinchwhistle)
(16993, 24737, 27602), -- 81978 (Kimzee Pinchwhistle)
(16646, 24251, 27602), -- 81972 (Kimzee Pinchwhistle)
(16596, 24717, 27602), -- 81443 (Krixel Pinchwhistle)
(16626, 24154, 27602), -- 81784 (Engineer Gazwitz)
(16913, 24616, 27602), -- 85152 (Mother Lode Crewman)
(16571, 24070, 27602), -- 81128 (Engineer Gazwitz)
(16957, 24674, 27602), -- 235295
(16688, 24240, 27602), -- 82516 (Corbix Chaching)
(16617, 24140, 27602), -- 81109 (Kimzee Pinchwhistle)
(16834, 24476, 27602), -- 84093 (Patient Shui)
(16835, 24477, 27602), -- 83930 (Kalaena Brightstar)
(16836, 24478, 27602), -- 83797 (Douglas Fellworth)
(18677, 27140, 27602), -- 96362 (Izzy Hollyfizzle)
(18779, 27322, 27602), -- 96362 (Izzy Hollyfizzle)
(17531, 24916, 27602), -- 82481 (Fiona)
(17422, 24851, 27602), -- 89075 (Delvar Ironfist)
(17306, 25678, 27602), -- 88598 (Chronicler Zataara)
(18372, 26457, 27602), -- 92213 (Archmage Khadgar)
(17319, 25730, 27602), -- 88633 (Deluwin Whisperfield)
(16613, 24441, 27602), -- 84455 (Assistant Brightstone)
(16390, 23761, 27602), -- 77209 (Baros Alexston)
(16670, 24209, 27602), -- 81152 (Scout Valdez)
(18371, 26456, 27602), -- 91913 (Exarch Yrel)
(16998, 9051, 27602), -- 82776 (Deedree)
(17010, 24806, 27602), -- 85857 (Jeff Miller)
(18322, 26356, 27602), -- 91024 (Jake the Fox)
(16905, 24599, 27602), -- 84776 (Aerun)
(18566, 26888, 27602), -- 94870 (Seer Kazal)
(17354, 25806, 27602), -- 88779 (Benjamin Brode)
(17330, 25783, 27602), -- 88779 (Benjamin Brode)
(17177, 25069, 27602), -- 86583 (Garrison Magus)
(16518, 23994, 27404), -- 80521 (Thaelin Darkanvil)
(16432, 23823, 27404), -- 79315 (Olin Umberhide)
(16429, 23809, 27404), -- 79537 (Exarch Maladaar)
(16433, 23824, 27404), -- 79675 (Lady Liadrin)
(16428, 23808, 27404), -- 79316 (Qiana Moonshadow)
(16405, 23740, 27404), -- 78560 (Archmage Khadgar)
(16641, 24170, 27404), -- 78556 (Ariok)
(16376, 23740, 27404), -- 78559 (Archmage Khadgar)
(16693, 24252, 27404), -- 78558 (Archmage Khadgar)
(16863, 24524, 27404), -- 78423 (Archmage Khadgar)
(16910, 24613, 27377), -- 85213 (Bodrick Grey)
(16723, 24306, 27377), -- 82270 (Vindicator Maraad)
(13723, 19717, 27377), -- 60795 (Lorewalker Cho)
(13724, 19719, 27377), -- 60796 (Mishi)
(13822, 19954, 27377), -- 60937 (Shado-Pan Guardian)
(13823, 19955, 27377), -- 60939 (Shado-Pan Warrior)
(20992, 31666, 27377), -- 120747 (Commander Shen-Li)
(13843, 19992, 27377), -- 62220 (Shado-Pan Sentinel)
(14609, 20669, 27377), -- 63650 (Dejected Grummle Trader)
(14614, 20673, 27377), -- 63612 (Snowshoe)
(14613, 20672, 27377), -- 63644 (Golden Snow)
(13831, 19995, 27377), -- 62227 (Ban Bearheart)
(13831, 19991, 27377), -- 61819 (Ban Bearheart)
(13836, 19999, 27377), -- 61454 (Suna Silentstrike)
(13832, 20004, 27377), -- 61820 (Lao-Chin the Iron Belly)
(13831, 19994, 27377), -- 61819 (Ban Bearheart)
(13836, 19972, 27377), -- 61454 (Suna Silentstrike)
(13832, 20003, 27377), -- 61820 (Lao-Chin the Iron Belly)
(13836, 19973, 27377), -- 61454 (Suna Silentstrike)
(13832, 19982, 27377), -- 61820 (Lao-Chin the Iron Belly)
(13830, 19966, 27377), -- 61512 (Kite Master Len)
(13839, 20001, 27377), -- 61816 (Lin Silentstrike)
(13831, 19967, 27377), -- 61819 (Ban Bearheart)
(13839, 19987, 27377), -- 61816 (Lin Silentstrike)
(13836, 19986, 27377), -- 61454 (Suna Silentstrike)
(13832, 19968, 27377), -- 61820 (Lao-Chin the Iron Belly)
(13831, 19993, 27377), -- 61819 (Ban Bearheart)
(13678, 19621, 27377), -- 60187 (Jin Warmkeg)
(13681, 19625, 27377), -- 60190 (Old Lady Fung)
(13680, 19624, 27377), -- 60189 (Ya Firebough)
(13683, 19939, 27377), -- 60161 (Shado-Master Chong)
(13683, 19938, 27377), -- 60161 (Shado-Master Chong)
(13683, 19630, 27377), -- 60161 (Shado-Master Chong)
(13794, 19878, 27377), -- 61519 (Trader Hozenpaw)
(13795, 19879, 27377), -- 62877 (Stained Mug)
(13720, 19712, 27377), -- 60587 (Kota Kon)
(13712, 19740, 27377), -- 60596 (Cousin Gootfur)
(14485, 20430, 27377), -- 63372 (Guardian of the Peak)
(13893, 20079, 27377), -- 59755 (Brother Oilyak)
(13892, 20017, 27377), -- 59755 (Brother Oilyak)
(13796, 19881, 27377), -- 60425 (Cousin Tealeaf)
(15055, 19352, 27377), -- 59413 (Cousin Mountainmusk)
(13712, 19688, 27377), -- 60596 (Cousin Gootfur)
(13694, 19665, 27377), -- 60503 (Uncle Keenbean)
(13686, 19635, 27377), -- 59894 (Brother Yakshoe)
(13685, 19633, 27377), -- 59452 (Brother Rabbitsfoot)
(13467, 19171, 27377), -- 58843 ("Dragonwing" Dan)
(13462, 19161, 27377), -- 58843 ("Dragonwing" Dan)
(13464, 19166, 27377), -- 58843 ("Dragonwing" Dan)
(13745, 19770, 27377), -- 56720 (Loon Mai)
(13301, 18859, 27377), -- 56714 (Master Bruised Paw)
(13301, 18858, 27377), -- 56714 (Master Bruised Paw)
(13437, 19126, 27377), -- 56714 (Master Bruised Paw)
(13301, 18810, 27377), -- 56714 (Master Bruised Paw)
(13310, 18833, 27377), -- 57120 (Wei Blacksoil)
(13310, 18832, 27377), -- 57120 (Wei Blacksoil)
(13318, 18845, 27377), -- 57122 (Shu-Li Spadepaw)
(13317, 18844, 27377), -- 57121 (Feng Spadepaw)
(13320, 18847, 27377), -- 57127 (Mia Marlfur)
(13316, 18843, 27377), -- 57126 (Zhang Marlfur)
(13311, 18834, 27377), -- 57123 (Haiyun Greentill)
(14635, 20696, 27377), -- 65160 (Blacktalon Watcher)
(14317, 20216, 27377), -- 63778 (Messenger Grummle)
(13748, 19773, 27377), -- 56720 (Loon Mai)
(13747, 19772, 27377), -- 56720 (Loon Mai)
(13746, 19771, 27377), -- 56720 (Loon Mai)
(13420, 19086, 27377), -- 58422 (Hemet Nesingwary Jr.)
(13424, 19080, 27377), -- 58461 (Hemet Nesingwary Jr.)
(13421, 19075, 27377), -- 58421 (Hemet Nesingwary)
(13420, 19074, 27377), -- 58422 (Hemet Nesingwary Jr.)
(13423, 19078, 27377), -- 58434 (Matt "Lucky" Gotcher)
(14323, 20224, 27377), -- 63822 (Tani)
(14795, 20932, 27377), -- 55143 (Sally Fizzlefury)
(14324, 20227, 27377), -- 63825 (Mr. Pleeb)
(13379, 18997, 27377), -- 58029 (Chen Stormstout)
(13378, 18996, 27377), -- 58028 (Li Li)
(13398, 19028, 27377), -- 56133 (Chen Stormstout)
(13398, 19027, 27377), -- 56133 (Chen Stormstout)
(15003, 21212, 27377), -- 56133 (Chen Stormstout)
(13622, 19528, 27377), -- 215705
(13470, 19179, 27377), -- 58706 (Gina Mudclaw)
(13749, 19776, 27377); -- 56133 (Chen Stormstout)

INSERT INTO `gossip_menu` (`MenuId`, `TextId`, `VerifiedBuild`) VALUES
(12380, 17401, 27326), -- 48014 (Nivvet Channelock)
(12380, 17400, 27326), -- 48014 (Nivvet Channelock)
(12377, 17397, 27326), -- 46591 (Colin Thundermar)
(12602, 17740, 27326), -- 49386 (Craw MacGraw)
(12130, 17036, 27326), -- 46378 (Dillan MacHurley)
(12059, 16907, 27326), -- 45904 (Angus Stillmountain)
(12143, 17055, 27326), -- 46628 (Flynn Dunwald)
(12141, 17052, 27326), -- 46143 (Flynn Dunwald)
(12142, 17053, 27326), -- 46177 (Keely Dunwald)
(12140, 17051, 27326), -- 46609 (Dunwald Victim)
(12139, 17046, 27326), -- 46175 (Eoin Dunwald)
(12138, 17014, 27326), -- 46174 (Cayden Dunwald)
(12116, 17013, 27326), -- 46174 (Cayden Dunwald)
(12115, 17012, 27326), -- 46174 (Cayden Dunwald)
(12114, 17011, 27326), -- 46174 (Cayden Dunwald)
(12135, 17013, 27326), -- 46174 (Cayden Dunwald)
(12136, 17012, 27326), -- 46174 (Cayden Dunwald)
(12137, 17011, 27326), -- 46174 (Cayden Dunwald)
(12160, 17099, 27326), -- 46804 (Keegan Firebeard)
(12165, 17104, 27326), -- 46968 (Mullan Gryphon)
(12166, 17105, 27326), -- 46969 (Mullan Gryphon)
(12247, 17212, 27326), -- 46813 (Mullan Gryphon Rider)
(12247, 17208, 27326), -- 46813 (Mullan Gryphon Rider)
(12266, 17228, 27326), -- 47465 (Injured Dragonmaw Straggler)
(12159, 17098, 27326), -- 46805 (Iain Firebeard)
(12157, 17096, 27326), -- 46923 (Meara)
(12057, 16906, 27326), -- 45173 (Talaa)
(12387, 17409, 27326), -- 45167 (Kurdran Wildhammer)
(12057, 16903, 27326), -- 45173 (Talaa)
(18639, 27072, 27326), -- 95928 (Rhol Landers)
(12362, 17367, 27326), -- 47902 (Lirastrasza)
(12164, 17103, 27326), -- 46939 (Mullan Gryphon)
(15067, 21297, 27326), -- 66822 (Goz Banefury)
(12158, 17097, 27326), -- 46926 (Parlan)
(12042, 16872, 27326), -- 45524 (Siege Tank Commander)
(12036, 16867, 27326), -- 45168 (Fargo Flintlocke)
(11944, 16766, 27326), -- 45170 (Simon Chandler)
(12386, 17407, 27326), -- 44806 (Fargo Flintlocke)
(11522, 16032, 27178), -- 41341 (Erunak Stonespeaker)
(11489, 16033, 27178), -- 41340 (Private Pollard)
(11513, 16067, 27178), -- 41340 (Private Pollard)
(11514, 16066, 27178), -- 41340 (Private Pollard)
(11510, 16064, 27178), -- 41340 (Private Pollard)
(11511, 16063, 27178), -- 41340 (Private Pollard)
(11508, 16062, 27178), -- 41340 (Private Pollard)
(11509, 16061, 27178), -- 41340 (Private Pollard)
(11327, 15783, 27178), -- 41324 (Private Pollard)
(12122, 17027, 27178), -- 46458 (Budd)
(12118, 17020, 27178), -- 46338 (Budd)
(11478, 16015, 27178), -- 40105 (Erunak Stonespeaker)
(11314, 17002, 27178), -- 39883 (Adarrah)
(11314, 15770, 27178), -- 39883 (Adarrah)
(11444, 15943, 27178), -- 39669 (Captain Samir)
(11442, 15938, 27178), -- 39667 (Adarrah)
(12213, 17166, 27101), -- 47159 (Commander Schnottz)
(18536, 6957, 27791), -- 94399 (Fleet Command Table)
(18542, 27070, 27791), -- 93822 (Merreck Vonder)
(18253, 7778, 27791), -- 90960 (Skyguard Thann)
(18260, 26263, 27791), -- 90309 (Exarch Yrel)
(18599, 26967, 27791), -- 95424 (Dawn-Seeker Krisek)
(18269, 26274, 27791), -- 91324 (Braknoth)
(18437, 26601, 27791), -- 93178 (Forika the Seer)
(18416, 26551, 27791), -- 91945 (Rangari Laara)
(18335, 26388, 27791), -- 91945 (Rangari Laara)
(18334, 26389, 27791), -- 91945 (Rangari Laara)
(18263, 26266, 27791), -- 91382 (Felsworn Deserter)
(18331, 26384, 27791), -- 91942 (Altauur)
(18333, 26386, 27791), -- 91944 (Rangari Sheera)
(18332, 26387, 27791), -- 91944 (Rangari Sheera)
(18415, 26550, 27791), -- 91942 (Altauur)
(18330, 26385, 27791), -- 91942 (Altauur)
(18412, 26542, 27791), -- 92805 (Z'tenga the Walker)
(18413, 26543, 27791), -- 92805 (Z'tenga the Walker)
(18620, 27007, 27791), -- 95650 (Skoller)
(18620, 27016, 27791), -- 95650 (Skoller)
(18228, 26181, 27791), -- 90644 (Lagar the Wise)
(18227, 26182, 27791), -- 90644 (Lagar the Wise)
(18670, 27101, 27791), -- 90974 (Vindicator Krethos)
(18670, 27136, 27791), -- 90974 (Vindicator Krethos)
(17542, 24901, 27602), -- 82656 (Tormmok)
(17038, 24900, 27602), -- 86317 (Reema)
(16353, 23687, 27602), -- 78538 (Vindicator Doruu)
(16357, 23695, 27602), -- 80993 (Archmage Elandra)
(16367, 23695, 27602), -- 78741 (Archmage Elandra)
(16354, 23689, 27602), -- 78538 (Vindicator Doruu)
(16352, 23686, 27602), -- 78534 (Ageilaa)
(18375, 26464, 27602), -- 91751 (Exarch Yrel)
(16313, 23606, 27602), -- 77664 (Aarko)
(16312, 23606, 27602), -- 77664 (Aarko)
(16399, 23766, 27602), -- 79434 (Soulbinder Tuulani)
(16308, 23598, 27602), -- 77582 (Soulbinder Nyami)
(16398, 23766, 27602), -- 79426 (Soulbinder Tuulani)
(16633, 24162, 27602), -- 81740 (Anchorite Ophira)
(16616, 24138, 27602), -- 81743 (Nissa Flamestrider)
(16634, 24163, 27602), -- 81841 (Savas)
(16635, 24164, 27602), -- 81842 (Todor)
(16642, 24171, 27602), -- 81925 (Ariuun)
(16637, 24166, 27602), -- 81879 (Defender Eneas)
(16627, 24155, 27602), -- 81785 (Siegecrafter Elaani)
(16629, 24157, 27602), -- 81798 (Bria Brightwing)
(16528, 24009, 27602), -- 80968 (Miall)
(16648, 24181, 27602), -- 80632 (Alliance Soldier)
(16630, 24158, 27602), -- 80628 (Miall)
(16447, 23841, 27602), -- 79970 (Vindicator Dalu)
(16448, 23843, 27602), -- 79977 (Soulbinder Halaari)
(16316, 23614, 27602), -- 77748 (Vindicator Gaabru)
(16401, 23767, 27602), -- 79452 (Vilonia)
(16160, 23330, 27602), -- 224825
(16692, 24250, 27602), -- 82571 (Atheeru Palestar)
(17110, 25154, 27602), -- 86949 (Zooti Fizzlefury)
(16850, 24552, 27602), -- 77195 (Archmage Khadgar)
(16814, 24506, 27602), -- 77195 (Archmage Khadgar)
(16878, 24547, 27602), -- 77195 (Archmage Khadgar)
(17094, 25130, 27602), -- 77192 (Thaelin Darkanvil)
(16298, 23555, 27602), -- 75805 (Archmage Khadgar)
(16500, 23959, 27602), -- 75803 (Vindicator Maraad)
(16501, 23960, 27602), -- 75804 (Yrel)
(16499, 23958, 27602), -- 77107 (Thrall)
(16498, 23957, 27602), -- 75874 (Thaelin Darkanvil)
(16392, 23762, 27602), -- 79329 (Miall)
(16486, 23931, 27602), -- 80351 (Crew Chief Dearii)
(16604, 24118, 27602), -- 81663 (Logistician Wells)
(16383, 23754, 27602), -- 79133 (Foreman Eksos)
(16987, 24726, 27602), -- 79963 (Quartermaster O'Riley)
(17321, 25732, 27602), -- 80768 (Alstan Mountainbrew)
(17541, 24938, 27602), -- 83947 (Kimzee Pinchwhistle)
(17443, 24912, 27602), -- 79611 (Qiana Moonshadow)
(17511, 24790, 27602), -- 82865 (Bruma Swiftstone)
(17032, 24851, 27602), -- 86084 (Delvar Ironfist)
(18498, 26742, 27602), -- 93907 (Amelia Clarke)
(18497, 26741, 27602), -- 93906 (Slugg Spinbolt)
(18492, 26740, 27602), -- 86176 (Ingrid Blackingot)
(18489, 26715, 27602), -- 86175 (Bregg Coppercast)
(4824, 5880, 27602), -- 88254 (Julia Watkins)
(17046, 24975, 27602), -- 86432 (Belosh)
(17183, 25277, 27602), -- 87063 (Joao Calhandro)
(17127, 25173, 27602), -- 86148 (Knewbie McGreen)
(17178, 25272, 27602), -- 87052 (Artificer Harlaan)
(17179, 25273, 27602), -- 87065 (Sean Catchpole)
(17148, 25236, 27602), -- 87243 (Zaalendor)
(17182, 25276, 27602), -- 87049 (Steven Cochrane)
(17181, 25275, 27602), -- 87057 (Leara Moonsilk)
(17152, 25243, 27602), -- 85923 (Rangari Laandon)
(17294, 25635, 27602), -- 88501 (Maldur Goldmantle)
(17153, 25244, 27602), -- 85917 (Aimee Goldforge)
(17268, 25555, 27602), -- 88184 (Arlysea Silveroak)
(17157, 25249, 27602), -- 85926 (Austin Windmill)
(17131, 25178, 27602), -- 87022 (Bob)
(17130, 25176, 27602), -- 85914 (Bil Sparktonic)
(17334, 25786, 27602), -- 86413 (Stormshield Guard)
(17312, 25685, 27602), -- 88155 (Challenger Savina)
(18324, 26967, 27602), -- 87391 (Fate-Twister Seress)
(17044, 24955, 27602), -- 86387 (Dawn-Seeker Rilak)
(17156, 25248, 27602), -- 86182 (Talon Guard Teth)
(17047, 24981, 27602), -- 86440 (Barney Fizzlestop)
(17048, 24982, 27602), -- 86441 (Prelate Soshia)
(17126, 25172, 27602), -- 85932 (Vindicator Nuurem)
(18275, 26286, 27602), -- 91483 (Fen Tao)
(18276, 26287, 27602), -- 91483 (Fen Tao)
(17049, 24983, 27602), -- 85963 (Orville Manfred)
(17245, 25519, 27602), -- 87048 (Katherine Joplin)
(17277, 25570, 27602), -- 87274 (Mustazaar)
(17128, 25174, 27602), -- 85956 (Jaesia Rosecheer)
(17336, 25788, 27602), -- 86413 (Stormshield Guard)
(17375, 25828, 27602), -- 86413 (Stormshield Guard)
(17372, 25824, 27602), -- 86413 (Stormshield Guard)
(17373, 25826, 27602), -- 86413 (Stormshield Guard)
(17374, 25827, 27602), -- 86413 (Stormshield Guard)
(17337, 25789, 27602), -- 86413 (Stormshield Guard)
(17371, 25825, 27602), -- 86413 (Stormshield Guard)
(17370, 25823, 27602), -- 86413 (Stormshield Guard)
(17367, 25820, 27602), -- 86413 (Stormshield Guard)
(17349, 25801, 27602), -- 86413 (Stormshield Guard)
(17369, 25822, 27602), -- 86413 (Stormshield Guard)
(17368, 25821, 27602), -- 86413 (Stormshield Guard)
(17366, 25819, 27602), -- 86413 (Stormshield Guard)
(17365, 25818, 27602), -- 86413 (Stormshield Guard)
(17364, 25817, 27602), -- 86413 (Stormshield Guard)
(17363, 25816, 27602), -- 86413 (Stormshield Guard)
(17362, 25815, 27602), -- 86413 (Stormshield Guard)
(17361, 25814, 27602), -- 86413 (Stormshield Guard)
(17356, 25808, 27602), -- 86413 (Stormshield Guard)
(17355, 25807, 27602), -- 86413 (Stormshield Guard)
(17353, 25805, 27602), -- 86413 (Stormshield Guard)
(17352, 25804, 27602), -- 86413 (Stormshield Guard)
(17351, 25803, 27602), -- 86413 (Stormshield Guard)
(17350, 25802, 27602), -- 86413 (Stormshield Guard)
(17335, 25787, 27602), -- 86413 (Stormshield Guard)
(17347, 25800, 27602), -- 86413 (Stormshield Guard)
(17348, 25797, 27602), -- 86413 (Stormshield Guard)
(17346, 25799, 27602), -- 86413 (Stormshield Guard)
(17345, 25798, 27602), -- 86413 (Stormshield Guard)
(17343, 25796, 27602), -- 86413 (Stormshield Guard)
(17344, 25793, 27602), -- 86413 (Stormshield Guard)
(17342, 25795, 27602), -- 86413 (Stormshield Guard)
(17341, 25794, 27602), -- 86413 (Stormshield Guard)
(17340, 25792, 27602), -- 86413 (Stormshield Guard)
(17339, 25791, 27602), -- 86413 (Stormshield Guard)
(17338, 25790, 27602), -- 86413 (Stormshield Guard)
(16355, 23691, 27602), -- 229314
(16365, 23713, 27602), -- 77982 (Rexxar)
(17280, 25591, 27602), -- 88276 (Archmage Modera)
(16601, 24106, 27602), -- 81530 (Anchorite Laanda)
(17288, 25609, 27602), -- 88390 (The Promise of Eternity)
(17009, 24761, 27602), -- 85413 (Weldon Barov)
(17000, 24747, 27602), -- 85418 (Lio the Lioness)
(17271, 24619, 27602), -- 88223 (Sergeant Crowler)
(16257, 23510, 27602), -- 80568 (Yrel)
(17535, 24930, 27602), -- 82495 (Rulkan)
(16430, 23810, 27602), -- 79789 (Eggtender Aloron)
(16975, 24707, 27602), -- 85573 (Elodor Villager)
(16974, 24705, 27602), -- 85569 (Elodor Fisherman)
(17197, 25421, 27602), -- 74969 (Maxine Quickshot)
(17308, 25680, 27602), -- 237790
(17089, 9849, 27602), -- 83825 (Mirathen)
(16118, 23221, 27602), -- 74343 (Vindicator Tenuum)
(16292, 23572, 27602), -- 75145 (Vindicator Maraad)
(16535, 23509, 27602), -- 73395 (Yrel)
(17092, 25125, 27602), -- 73395 (Yrel)
(16465, 23880, 27602), -- 79664 (K'ara)
(16119, 23222, 27602), -- 72413 (Exarch Akama)
(16254, 23507, 27602), -- 76516 (K'ara)
(16148, 23279, 27602), -- 77282 (Prophet Velen)
(16556, 24048, 27602), -- 81173 (Illuminate Praavi)
(16555, 24047, 27602), -- 81176 (Rangari Saa'to)
(17426, 25004, 27547), -- 77781 (Garm)
(16482, 23915, 27547), -- 80293 (Kat'la)
(16487, 23932, 27547), -- 76186 (Hara Bloodfury)
(16258, 23511, 27547), -- 75884 (Rulkan)
(16236, 23470, 27547), -- 75884 (Rulkan)
(16868, 24528, 27547), -- 84248 (Justin Timberlord)
(16797, 24424, 27547), -- 83858 (Khadgar's Servant)
(16739, 24338, 27547), -- 82492 (Vindicator Onaala)
(16743, 24341, 27547), -- 82491 (Rangari Chel)
(16745, 24347, 27547), -- 82489 (Apprentice Artificer Andren)
(16744, 24344, 27547), -- 82492 (Vindicator Onaala)
(16744, 24345, 27547), -- 82492 (Vindicator Onaala)
(16745, 24346, 27547), -- 82489 (Apprentice Artificer Andren)
(16743, 24342, 27547), -- 82491 (Rangari Chel)
(16690, 24246, 27547), -- 88972 (Exarch Maladaar)
(16690, 24245, 27547), -- 88972 (Exarch Maladaar)
(17013, 24819, 27547), -- 80076 (Exarch Othaar)
(16674, 24218, 27547), -- 82287 (Exarch Naielle)
(16673, 24217, 27547), -- 82288 (Exarch Hataaru)
(16287, 23564, 27547), -- 77264 (Marnaa)
(16536, 24018, 27547), -- 81031 (Roluna)
(16533, 24014, 27547), -- 80989 (Daruun)
(16532, 24013, 27547), -- 80991 (Gaades)
(16564, 24061, 27547), -- 80897 (Chelie Coldanvil)
(16526, 24007, 27547); -- 80897 (Chelie Coldanvil)

INSERT INTO `gossip_menu` (`MenuId`, `TextId`, `VerifiedBuild`) VALUES
(16527, 24008, 27547), -- 80897 (Chelie Coldanvil)
(16999, 24745, 27547), -- 85716 (Vaerdal)
(16530, 24011, 27547), -- 80995 (Endoraes)
(16986, 24725, 27547), -- 77733 (Ron Ashton)
(16862, 24521, 27547), -- 84372 (Madari)
(16994, 24741, 27547), -- 77730 (Timothy Leens)
(17069, 25079, 27547), -- 85708 (Segumi)
(16750, 24349, 27547), -- 83491 (Eileese Shadowsong)
(18564, 26884, 27547), -- 85418 (Lio the Lioness)
(17005, 24751, 27547), -- 85418 (Lio the Lioness)
(16464, 23878, 27547), -- 80159 (Arsenio Zerep)
(17199, 25423, 27547), -- 81348 (Rachelle Black)
(16966, 24692, 27547), -- 85514 (Olly Nimkip)
(16962, 24678, 27547), -- 85344 (Naron Bloomthistle)
(16148, 24180, 27547), -- 74043 (Prophet Velen)
(16535, 24017, 27547), -- 73395 (Yrel)
(17989, 25930, 27547), -- 89236 (Ancient Waygate Protector)
(16552, 24038, 27547), -- 81133 (Artificer Kallaes)
(16567, 24064, 27547), -- 81124 (Prelate Minara)
(16566, 24063, 27547), -- 81122 (Prelate Zaash)
(16568, 24065, 27547), -- 81126 (Prelate Luari)
(16561, 24056, 27547), -- 81180 (Trapper Zera)
(7742, 9478, 27547), -- 77184 (Archmage Khadgar)
(15791, 22682, 27547), -- 72637 (Cordana Felsong)
(16371, 22846, 27547), -- 77417 (Image of Archmage Khadgar)
(16609, 24131, 27547), -- 81912 (Foreman Zipfizzle)
(15802, 22706, 27547), -- 72871 (All-Seeing Eye)
(15777, 22665, 27547), -- 72623 (Delas Moonfang)
(17135, 25183, 27547), -- 76838 (Jorril)
(16463, 23877, 27547), -- 79966 (Lost Packmule)
(17235, 25477, 27547), -- 237486
(17235, 25479, 27547), -- 237486
(16440, 23832, 27547), -- 79457 (Vindicator Maraad)
(17064, 25072, 27547), -- 86589 (Watchman Tilnia)
(16598, 24100, 27547), -- 81441 (Shelly Hamby)
(16812, 24135, 27547), -- 84455 (Assistant Brightstone)
(16613, 24135, 27547), -- 84455 (Assistant Brightstone)
(16521, 23999, 27547), -- 79891 (Jenny Larson)
(16643, 24172, 27547), -- 81935 (Scrap Sparkfuse)
(16871, 24531, 27547), -- 79243 (Baros Alexston)
(16411, 23776, 27547), -- 79242 (Archmage Khadgar)
(16404, 23771, 27547), -- 79241 (Prophet Velen)
(13847, 20112, 27377), -- 62538 (Kil'ruk the Wind-Reaver)
(14314, 20213, 27377), -- 63758 (Kaz'tik the Manipulator)
(14272, 20119, 27377), -- 63071 (Skeer the Bloodseeker)
(14271, 20118, 27377), -- 62180 (Korven the Prime)
(14655, 20732, 27377), -- 65305 (Iyyokuk the Lucid)
(14656, 20733, 27377), -- 65303 (Ka'roz the Locust)
(13888, 20075, 27377), -- 62774 (Malik the Unscathed)
(15365, 22050, 27377), -- 65395 (Klaxxi'va Ik)
(14497, 20504, 27377), -- 63317 (Captain "Soggy" Su-Dao)
(14511, 20518, 27377), -- 63349 (Deck Boss Arie)
(14302, 20177, 27377), -- 63317 (Captain "Soggy" Su-Dao)
(14398, 20322, 27377), -- 64259 (Master Angler Ju Lien)
(14299, 20497, 27377), -- 63349 (Deck Boss Arie)
(14299, 20496, 27377), -- 63349 (Deck Boss Arie)
(14336, 20243, 27377), -- 63955 (Dog)
(14299, 20171, 27377), -- 63349 (Deck Boss Arie)
(14300, 20173, 27377), -- 63280 (Deckhand)
(14301, 20174, 27377), -- 63280 (Deckhand)
(14663, 20763, 27377), -- 64599 (Ambersmith Zikk)
(14272, 20751, 27377), -- 63071 (Skeer the Bloodseeker)
(14269, 20116, 27377), -- 63037 (Han Stormstout)
(14044, 20099, 27377), -- 62666 (Sapmaster Vu)
(14046, 20100, 27377), -- 62667 (Lya of Ten Songs)
(14275, 20121, 27377), -- 62771 (Chief Rikkitun)
(15005, 21214, 27377), -- 62779 (Chen Stormstout)
(15006, 21213, 27377), -- 67138 (Chen Stormstout)
(14053, 20103, 27377), -- 62666 (Sapmaster Vu)
(14049, 20102, 27377), -- 62845 (Big Dan Stormstout)
(14043, 20098, 27377), -- 62845 (Big Dan Stormstout)
(14055, 20104, 27377), -- 62667 (Lya of Ten Songs)
(14596, 20637, 27377), -- 64815 (Kor'ik)
(14271, 20139, 27377), -- 62232 (Klaxxi Warrior)
(14271, 20138, 27377), -- 62232 (Klaxxi Warrior)
(15049, 21284, 27377), -- 66739 (Wastewalker Shu)
(14484, 20429, 27377), -- 64344 (Kaz'tik the Manipulator)
(14484, 20428, 27377), -- 63876 (Kaz'tik the Manipulator)
(13847, 20061, 27377), -- 62538 (Kil'ruk the Wind-Reaver)
(14668, 20769, 27377), -- 62666 (Sapmaster Vu)
(14667, 20768, 27377), -- 62666 (Sapmaster Vu)
(14666, 20767, 27377), -- 62666 (Sapmaster Vu)
(14665, 20766, 27377), -- 62666 (Sapmaster Vu)
(14664, 20765, 27377), -- 62666 (Sapmaster Vu)
(14807, 20955, 27377), -- 65220 (Zit'tix)
(14641, 20703, 27377), -- 65186 (Poisoncrafter Kil'zit)
(13847, 20022, 27377), -- 62202 (Kil'ruk the Wind-Reaver)
(13847, 20015, 27377), -- 62202 (Kil'ruk the Wind-Reaver)
(13838, 19983, 27377), -- 62166 (Marksman Lann)
(13837, 19978, 27377), -- 62112 (Bowmistress Li)
(13882, 20067, 27377), -- 62380 (Snow Blossom)
(13883, 20068, 27377), -- 62303 (Yalia Sagewhisper)
(13848, 20011, 27377), -- 62354 (Fei Li)
(13894, 20082, 27377), -- 62810 (Moshu the Arcane)
(13894, 20080, 27377), -- 62810 (Moshu the Arcane)
(13841, 19989, 27377), -- 61482 (Tai Ho)
(13877, 20053, 27377), -- 61585 (Yak-Keeper Kyana)
(13876, 20052, 27377), -- 61584 (Sentinel Commander Qipan)
(13874, 20050, 27377), -- 61580 (Ogo the Elder)
(13875, 20051, 27377), -- 61581 (Ogo the Younger)
(15090, 21469, 27377), -- 66918 (Seeker Zusshi)
(13842, 19990, 27377), -- 61625 (Provisioner Bamfu)
(15321, 21239, 27377), -- 68463 (Burning Pandaren Spirit)
(15570, 22365, 27377), -- 70360 (Vereesa Windrunner)
(15577, 22374, 27377), -- 67995 (Captain Elleane Wavecrest)
(15576, 22373, 27377), -- 67993 (Vereesa Windrunner)
(15516, 22278, 27377), -- 67992 (Lady Jaina Proudmoore)
(14278, 20124, 27377), -- 62978 (Lao-Chin the Iron Belly)
(14307, 20190, 27377), -- 63617 (Taoshi)
(14306, 20189, 27377), -- 63616 (Tenwu of the Red Smoke)
(14529, 20540, 27377), -- 63614 (Ling of the Six Pools)
(14996, 21205, 27377), -- 66409 (Lorewalker Pao)
(13849, 20012, 27377), -- 62304 (Ban Bearheart)
(13884, 20071, 27377), -- 62546 (Protector Yi)
(14276, 20122, 27377), -- 62550 (Chao the Voice)
(13844, 20007, 27377), -- 62275 (Taran Zhu)
(14798, 20937, 27377), -- 62278 (Rensai Oakhide)
(13846, 20006, 27377), -- 62274 (Taran Zhu)
(13845, 20005, 27377), -- 62273 (Taran Zhu)
(14846, 21006, 27377), -- 62124 (Initiate Pao-Me)
(13826, 19962, 27377), -- 61881 (Initiate Feng)
(13825, 19961, 27377), -- 61880 (Initiate Chao)
(13804, 19897, 27377), -- 61066 (Taran Zhu)
(13828, 19964, 27377), -- 61470 (Septi the Herbalist)
(13827, 19963, 27377), -- 61468 (Taoshi)
(13781, 19862, 27377), -- 61378 (Scout Wei-Chin)
(13799, 19886, 27377), -- 61395 (Scout Long)
(13798, 19885, 27377), -- 61396 (Scout Ying)
(13797, 19884, 27377), -- 61397 (Scout Jai-gan)
(13804, 19896, 27377), -- 61066 (Taran Zhu)
(13731, 19733, 27377), -- 60622 (Orbiss)
(13731, 19732, 27377), -- 60857 (Orbiss)
(13731, 19731, 27377), -- 60857 (Orbiss)
(13731, 19730, 27377), -- 60857 (Orbiss)
(13739, 19808, 27377), -- 60864 (Yalia Sagewhisper)
(13762, 19819, 27377), -- 61261 (Ban Bearheart)
(13734, 19809, 27377), -- 60903 (Xiao Tu)
(13762, 19818, 27377), -- 61261 (Ban Bearheart)
(13739, 19806, 27377), -- 60864 (Yalia Sagewhisper)
(13739, 19764, 27377), -- 60864 (Yalia Sagewhisper)
(13762, 19817, 27377), -- 61261 (Ban Bearheart)
(13734, 19743, 27377), -- 60951 (Shado-Pan Ranger)
(13739, 19763, 27377), -- 60864 (Yalia Sagewhisper)
(13722, 19721, 27377), -- 60735 (Katak the Defeated)
(13730, 19746, 27377), -- 60687 (Ban Bearheart)
(13729, 19745, 27377), -- 60684 (Suna Silentstrike)
(13730, 19749, 27377), -- 60687 (Ban Bearheart)
(13735, 19747, 27377), -- 60899 (Lin Silentstrike)
(13733, 19742, 27377), -- 60899 (Lin Silentstrike)
(13722, 19718, 27377), -- 60735 (Katak the Defeated)
(13729, 19727, 27377), -- 60684 (Suna Silentstrike)
(13730, 19729, 27377), -- 60687 (Ban Bearheart)
(13728, 19725, 27377), -- 60688 (Taran Zhu)
(13729, 19726, 27377), -- 60684 (Suna Silentstrike)
(13730, 19728, 27377), -- 60687 (Ban Bearheart)
(14636, 20697, 27377), -- 65171 (Alin the Finder)
(14599, 20653, 27377), -- 64848 (Anduin Wrynn)
(14600, 20656, 27377), -- 64851 (Zhi the Harmonious)
(14567, 20590, 27377), -- 64540 (Anduin Wrynn)
(13753, 19786, 27377), -- 61119 (Sweaty Glove)
(13810, 19856, 27377), -- 61651 (Master Lao)
(13778, 19858, 27377), -- 61212 (Tiger Temple Spectator)
(13777, 19856, 27377), -- 61211 (Tiger Temple Monk)
(14595, 20636, 27377), -- 60981 (Lin Tenderpaw)
(15041, 21276, 27377), -- 66360 (Master Brandom)
(21666, 32996, 27377), -- 128106 (Zidormi)
(13865, 20034, 27377), -- 64978 (Number Nine Jia)
(14954, 21144, 27377), -- 66207 (Master Hsu)
(14961, 21152, 27377), -- 66258 (Master Cheng)
(14956, 21147, 27377), -- 66253 (Master Kistane)
(14957, 21148, 27377), -- 66254 (Master Woo)
(14993, 21198, 27377), -- 66355 (Master Marshall)
(14992, 21197, 27377), -- 66354 (Master Cannon)
(14986, 21184, 27377), -- 66353 (Master Chang)
(15612, 22422, 27377), -- 70470 (Feng Zhe)
(14994, 21199, 27377), -- 66357 (Master Bier)
(13718, 19683, 27377), -- 60757 (Sage Liao)
(13711, 19752, 27377), -- 60436 (Li Hai)
(13718, 19720, 27377), -- 60785 (Sage Liao)
(14867, 21028, 27377), -- 65855 (Mishi)
(15062, 20643, 27377), -- 63784 (Lorewalker Cho)
(14288, 20163, 27377), -- 62629 (Zandalari Prisoner)
(15059, 20648, 27377), -- 63524 (Elder Hou)
(15061, 20646, 27377), -- 63757 (Elder Chi)
(14914, 20639, 27377), -- 62707 (Shomi)
(13821, 19950, 27377), -- 63750 (Lorewalker Cho)
(14326, 20229, 27377), -- 61496 (Steelbender Doshu)
(15076, 20030, 27377), -- 61534 (Shomi)
(14915, 20641, 27377), -- 61495 (Elder Shu)
(13864, 20030, 27377), -- 61503 (Shomi)
(14304, 20180, 27377), -- 61417 (Exhausted Defender)
(14305, 20180, 27377), -- 61381 (Exhausted Defender)
(14325, 20228, 27377), -- 60605 (Liu Ze)
(15060, 20645, 27377), -- 62970 (Elder Chi)
(15058, 20647, 27377), -- 62971 (Elder Hou)
(15057, 21291, 27377), -- 64070 (Frightened Villager)
(14597, 20649, 27377), -- 64836 (Zasha)
(14891, 21051, 27377), -- 64830 (Toshi)
(13761, 19816, 27377), -- 61380 (Shin Whispercloud)
(13760, 19815, 27377), -- 61379 (Lin Whispercloud)
(13759, 19719, 27377), -- 61382 (Mishi)
(14270, 20117, 27377), -- 61297 (Image of Lorewalker Cho)
(13732, 19737, 27377), -- 60887 (Mishi)
(13723, 19796, 27377), -- 60795 (Lorewalker Cho)
(14640, 20702, 27377), -- 65172 (Len at Arms)
(13745, 19775, 27377), -- 56720 (Loon Mai)
(13745, 19774, 27377), -- 56720 (Loon Mai)
(13665, 19606, 27377), -- 59857 (Miss Fanny)
(13664, 19599, 27377), -- 56474 (Mudmug)
(13665, 19605, 27377), -- 59857 (Miss Fanny)
(13689, 19653, 27377), -- 60173 (Jay Cloudfall)
(13690, 19654, 27377), -- 60139 (Wise Ana Wu)
(13689, 19652, 27377), -- 60173 (Jay Cloudfall)
(14039, 20097, 27377), -- 62872 (Cranfur the Noodler)
(13689, 19651, 27377), -- 60173 (Jay Cloudfall)
(14648, 20723, 27377), -- 65289 (Brewmaster Bo)
(13713, 19697, 27377), -- 60506 (Thelonius)
(13714, 19705, 27377), -- 60506 (Thelonius)
(13497, 19230, 27377), -- 58821 (Lyalia)
(13460, 19159, 27377), -- 58976 (Lyalia)
(13446, 19228, 27377), -- 58745 (Lorekeeper Vaeldrin)
(13440, 19133, 27377), -- 58954 (Ambassador Len)
(13492, 19215, 27377), -- 58711 (Wounded Traveller)
(13493, 19217, 27377), -- 58954 (Ambassador Len)
(13494, 19216, 27377), -- 58954 (Ambassador Len)
(13487, 19195, 27377), -- 58784 (Incursion Huntress)
(13455, 19227, 27377), -- 56114 (Kang Bramblestaff)
(13497, 19224, 27377), -- 58821 (Lyalia)
(15139, 21701, 27377), -- 56114 (Kang Bramblestaff)
(13455, 19152, 27377), -- 56114 (Kang Bramblestaff)
(13441, 19134, 27377), -- 58278 (Tired Shushen)
(13441, 19135, 27377), -- 58278 (Tired Shushen)
(13639, 19557, 27377), -- 59719 (Chi-Ji)
(13607, 19509, 27377), -- 59608 (Anduin Wrynn)
(13611, 19527, 27377), -- 59653 (Chi-Ji)
(13513, 19287, 27377), -- 59138 (Koro Mistwalker)
(13537, 19292, 27377), -- 59188 (Anduin Wrynn)
(13535, 19288, 27377), -- 58609 (Anduin Wrynn)
(13513, 19259, 27377), -- 59138 (Koro Mistwalker)
(13468, 19274, 27377), -- 58547 (Koro Mistwalker)
(13468, 19180, 27377), -- 58547 (Koro Mistwalker)
(15092, 21492, 27377), -- 58609 (Anduin Wrynn)
(15091, 21491, 27377), -- 58609 (Anduin Wrynn)
(13454, 19150, 27377), -- 58735 (Lyalia)
(13446, 19249, 27377), -- 58745 (Lorekeeper Vaeldrin)
(13446, 19141, 27377), -- 58745 (Lorekeeper Vaeldrin)
(13189, 18591, 27377), -- 55597 (Na Lek)
(13488, 19198, 27377), -- 58814 (Kang Bramblestaff)
(15716, 22574, 27377), -- 70948 (Jonathan Chen)
(15720, 22578, 27377); -- 70944 (Shappu the Wise)

INSERT INTO `gossip_menu` (`MenuId`, `TextId`, `VerifiedBuild`) VALUES
(14923, 21094, 27377), -- 65748 (Uncle Deming)
(14916, 21087, 27377), -- 65745 (Duyi Edgewater)
(15714, 22572, 27377), -- 70949 (Jae-Sun Di Fo)
(15715, 22573, 27377), -- 70945 (Jash Fu-Hsing)
(15717, 22575, 27377), -- 70946 (Din Ayala)
(14917, 21088, 27377), -- 65890 (Maolin Edgewater)
(15722, 22580, 27377), -- 70951 (Tom Wat)
(15721, 22579, 27377), -- 70950 (Hilda)
(14924, 21095, 27377), -- 65744 (Jun-Jun Edgewater)
(13717, 19709, 27377), -- 59584 (Fisherman Haito)
(14310, 20203, 27377), -- 63721 (Nat Pagle)
(14328, 20232, 27377), -- 60674 (John "Big Hook" Marsock)
(14334, 20241, 27377), -- 60135 (Trawler Yotimo)
(14333, 20240, 27377), -- 60135 (Trawler Yotimo)
(15046, 21281, 27377), -- 66733 (Mo'ruk)
(13454, 19151, 27377), -- 58735 (Lyalia)
(13498, 19225, 27377), -- 58735 (Lyalia)
(13496, 19221, 27377), -- 58745 (Lorekeeper Vaeldrin)
(13495, 19219, 27377), -- 58790 (Alynna Whisperblade)
(13491, 19212, 27377), -- 58790 (Alynna Whisperblade)
(13499, 19226, 27377), -- 58926 (Magister Xintar)
(13455, 19153, 27377), -- 56114 (Kang Bramblestaff)
(13519, 19266, 27377), -- 59151 (Zhu's Watch Courier)
(13384, 19011, 27377), -- 58779 (Daggle Bombstrider)
(13419, 19072, 27377), -- 58779 (Daggle Bombstrider)
(13351, 19045, 27377), -- 57744 (Mei Barrelbottom)
(13404, 19047, 27377), -- 57744 (Mei Barrelbottom)
(13403, 19046, 27377), -- 57744 (Mei Barrelbottom)
(13350, 21699, 27377), -- 57830 (Sunni)
(13349, 21698, 27377), -- 57825 (Yun)
(13387, 19015, 27377), -- 56115 (Ken-Ken)
(15141, 21702, 27377), -- 56115 (Ken-Ken)
(13351, 19031, 27377), -- 57744 (Mei Barrelbottom)
(13354, 18946, 27377), -- 58376 (Yi-Mo Longbrow)
(13353, 18945, 27377), -- 58376 (Yi-Mo Longbrow)
(13355, 18947, 27377), -- 58376 (Yi-Mo Longbrow)
(13353, 18944, 27377), -- 58376 (Yi-Mo Longbrow)
(13387, 19014, 27377), -- 56115 (Ken-Ken)
(13387, 19013, 27377), -- 56115 (Ken-Ken)
(13350, 18938, 27377), -- 57830 (Sunni)
(13349, 18937, 27377), -- 57825 (Yun)
(14050, 20101, 27377), -- 62879 (Rude Sho)
(13351, 18939, 27377), -- 57744 (Mei Barrelbottom)
(13536, 19291, 27377), -- 59224 (Shai Cliffwatcher)
(13333, 18884, 27377), -- 57211 (Grainlord Kai)
(13333, 18883, 27377), -- 57211 (Grainlord Kai)
(13334, 18887, 27377), -- 57385 (Gai Lan)
(13334, 18888, 27377), -- 57385 (Gai Lan)
(13339, 18894, 27377), -- 57408 (Mina Mudclaw)
(15130, 21696, 27377), -- 57401 (Mung-Mung)
(13850, 20016, 27377), -- 62377 (Gardener Fran)
(13850, 18897, 27377), -- 62377 (Gardener Fran)
(13600, 19475, 27377), -- 57298 (Farmer Fung)
(13332, 18882, 27377), -- 57298 (Farmer Fung)
(13601, 19477, 27377), -- 58761 (Tina Mudclaw)
(13593, 19426, 27377), -- 58761 (Tina Mudclaw)
(13338, 18893, 27377), -- 57402 (Haohan Mudclaw)
(13602, 19478, 27377), -- 57402 (Haohan Mudclaw)
(13853, 18893, 27377), -- 62385 (Den Mudclaw)
(13578, 19394, 27377), -- 59532 (Wika-Wika)
(13597, 19473, 27377), -- 58709 (Chee Chee)
(13594, 19443, 27377), -- 58709 (Chee Chee)
(15047, 21282, 27377), -- 66734 (Farmer Nishi)
(13409, 19158, 27377), -- 56474 (Mudmug)
(13445, 19583, 27377), -- 58646 (Farmer Yoon)
(13653, 19584, 27377), -- 58646 (Farmer Yoon)
(15156, 21720, 27377), -- 58646 (Farmer Yoon)
(13663, 19596, 27377), -- 58646 (Farmer Yoon)
(13662, 19595, 27377), -- 58646 (Farmer Yoon)
(13661, 19594, 27377), -- 58646 (Farmer Yoon)
(13660, 19593, 27377), -- 58646 (Farmer Yoon)
(13659, 19592, 27377), -- 58646 (Farmer Yoon)
(13658, 19591, 27377), -- 58646 (Farmer Yoon)
(13657, 19590, 27377), -- 58646 (Farmer Yoon)
(13656, 19589, 27377), -- 58646 (Farmer Yoon)
(13655, 19587, 27377), -- 58646 (Farmer Yoon)
(13654, 19585, 27377), -- 58646 (Farmer Yoon)
(13642, 19562, 27377), -- 58718 (Merchant Greenfield)
(13475, 19185, 27377), -- 58706 (Gina Mudclaw)
(13476, 19184, 27377), -- 58706 (Gina Mudclaw)
(13485, 19194, 27377), -- 58706 (Gina Mudclaw)
(13484, 19193, 27377), -- 58706 (Gina Mudclaw)
(13483, 19192, 27377), -- 58706 (Gina Mudclaw)
(13482, 19191, 27377), -- 58706 (Gina Mudclaw)
(13481, 19190, 27377), -- 58706 (Gina Mudclaw)
(13480, 19189, 27377), -- 58706 (Gina Mudclaw)
(13479, 19188, 27377), -- 58706 (Gina Mudclaw)
(13477, 19186, 27377), -- 58706 (Gina Mudclaw)
(13478, 19187, 27377), -- 58706 (Gina Mudclaw)
(13567, 19181, 27377), -- 58706 (Gina Mudclaw)
(13469, 19376, 27377), -- 58706 (Gina Mudclaw)
(13445, 19618, 27377), -- 58646 (Farmer Yoon)
(13640, 19564, 27377), -- 58718 (Merchant Greenfield)
(13641, 19563, 27377), -- 58718 (Merchant Greenfield)
(14403, 20329, 27377), -- 58646 (Farmer Yoon)
(14425, 20351, 27377), -- 64314 (Seedkeeper Shing Sing)
(14430, 20361, 27377), -- 64327 (Old Man Whitewhiskers)
(14572, 20603, 27377), -- 64597 (Nana Mudclaw)
(14426, 20352, 27377), -- 64315 (Stonecarver Mac)
(13582, 19404, 27377), -- 59581 (Spicemaster Jin Jao)
(14427, 20354, 27377), -- 64316 (Xiao Niao the Nightingale)
(13584, 19406, 27377), -- 59582 (Innkeeper Lei Lan)
(13583, 19405, 27377), -- 59583 (Trader Jambeezi)
(13585, 19407, 27377), -- 59585 (Lolo Lio)
(14379, 20624, 27377), -- 64231 (Sungshin Ironpaw)
(14585, 20624, 27377), -- 64395 (Nam Ironpaw)
(14418, 20344, 27377), -- 64302 (Archie Wandswaddle)
(14422, 20620, 27377), -- 58716 (Jian Ironpaw)
(14416, 20343, 27377), -- 64301 (Reagor Kennessy)
(13596, 19466, 27377), -- 58708 (Sho)
(13608, 19513, 27377), -- 58717 (Bobo Ironpaw)
(15610, 22420, 27377), -- 70461 (Milly Greenfield)
(14581, 20618, 27377), -- 58713 (Anthea Ironpaw)
(13595, 19460, 27377), -- 58707 (Old Hillpaw)
(13609, 19526, 27377), -- 58712 (Kol Ironpaw)
(14417, 20342, 27377), -- 64304 (Eloanna)
(14584, 20622, 27377), -- 58714 (Mei Mei Ironpaw)
(14583, 20621, 27377), -- 58715 (Yan Ironpaw)
(13445, 19140, 27377), -- 58646 (Farmer Yoon)
(13442, 19136, 27377), -- 58721 (Farmer Yoon)
(14423, 20348, 27377), -- 64312 (Grainsorter Pei)
(13409, 19056, 27377), -- 56474 (Mudmug)
(14424, 20350, 27377), -- 64313 (Mama Min)
(15579, 22376, 27377), -- 70398 (Ben of the Booming Voice)
(15597, 22394, 27377), -- 70398 (Ben of the Booming Voice)
(15596, 22393, 27377), -- 70398 (Ben of the Booming Voice)
(13343, 18900, 27377), -- 57405 (Silkmaster Tsai)
(13342, 18899, 27377), -- 57407 (Master Goh)
(13336, 18935, 27377), -- 57424 (Journeyman Chu)
(13342, 18898, 27377), -- 57407 (Master Goh)
(13344, 18908, 27377), -- 57433 (Loommaster Jeng)
(13336, 18891, 27377), -- 57424 (Journeyman Chu)
(13327, 18907, 27377), -- 56773 (Yan)
(13327, 18906, 27377), -- 56773 (Yan)
(13300, 18862, 27377), -- 56802 (Zhang Yue)
(13315, 18861, 27377), -- 56113 (Clever Ashyo)
(13315, 18842, 27377), -- 56113 (Clever Ashyo)
(13300, 18807, 27377), -- 56802 (Zhang Yue)
(14890, 18676, 27377), -- 65861 (Sen the Optimist)
(13327, 18878, 27377), -- 56773 (Yan)
(13740, 19767, 27377), -- 56474 (Mudmug)
(13279, 21212, 27377), -- 56133 (Chen Stormstout)
(13279, 21213, 27377), -- 56133 (Chen Stormstout)
(13750, 19777, 27377), -- 56549 (Li Li)
(13751, 19778, 27377), -- 56549 (Li Li)
(13276, 21211, 27377), -- 56133 (Chen Stormstout)
(13742, 19766, 27377), -- 56474 (Mudmug)
(13741, 19765, 27377), -- 56474 (Mudmug)
(13270, 18735, 27377), -- 56133 (Chen Stormstout)
(14383, 20306, 27377), -- 63484 (Len the Whisperer)
(14315, 21632, 27377), -- 63367 (Brewmaster Boof)
(14363, 20277, 27377), -- 64012 (Egg Shell)
(16471, 23888, 27377), -- 80218 (Retired Exchange Guard)
(14330, 20237, 27377), -- 62917 (Tong the Fixer)
(15605, 22411, 27377), -- 70436 (Blacktalon Quartermaster)
(14936, 21115, 27377), -- 64616 (Wrathion)
(14934, 21108, 27377), -- 64616 (Wrathion)
(15114, 21627, 27377), -- 67059 (Four Winds Trader)
(15113, 21626, 27377), -- 64953 (Lorewalker Shuchun)
(13885, 20072, 27377), -- 62738 (Highroad Grummle)
(13244, 18669, 27377), -- 56208 (Francis the Shepherd Boy)
(13243, 18668, 27377), -- 56205 (Liang Thunderfoot)
(13253, 18697, 27377), -- 56133 (Chen Stormstout)
(13230, 18689, 27377), -- 56192 (Miss Fanny)
(13230, 18687, 27377), -- 56192 (Miss Fanny)
(13230, 18649, 27377), -- 56192 (Miss Fanny)
(13230, 18688, 27377), -- 56192 (Miss Fanny)
(13230, 18686, 27377), -- 56192 (Miss Fanny)
(13237, 18659, 27377), -- 56204 (Pang Thunderfoot)
(13242, 18667, 27377), -- 56110 (Xiao)
(13242, 20021, 27377), -- 56110 (Xiao)
(13251, 18660, 27377), -- 56204 (Pang Thunderfoot)
(15001, 21210, 27377), -- 56133 (Chen Stormstout)
(13416, 19063, 27377), -- 56113 (Clever Ashyo)
(13415, 19062, 27377), -- 56115 (Ken-Ken)
(13418, 19066, 27377), -- 56111 (Lin Tenderpaw)
(13417, 19064, 27377), -- 56112 (Kang Bramblestaff)
(12950, 18221, 27326), -- 53925 (Aggra)
(12943, 18208, 27326), -- 53738 (Aggra)
(12940, 18204, 27326), -- 53738 (Aggra)
(12015, 16839, 27326), -- 45408 (D'lom the Collector)
(12009, 16728, 27326), -- 42465 (Therazane)
(11690, 16367, 27326), -- 42471 (Boden the Imposing)
(12438, 17491, 27326), -- 44973 (Ruberick)
(18637, 27063, 27326), -- 95893 (Forinn Stoneheart)
(11950, 16777, 27326), -- 44353 (Stormcaller Mylra)
(12234, 17178, 27326), -- 47197 (Flint Oremantle)
(11773, 17177, 27326), -- 43897 (Pyrium Lodestone)
(11692, 16373, 27326), -- 43071 (Crag Rockcrusher)
(12930, 18186, 27326), -- 53652 (Aggra)
(12938, 18202, 27326), -- 53519 (Aggra)
(12482, 17559, 27326), -- 49204 (Brann Bronzebeard)
(12231, 17174, 27326), -- 47158 (Harrison Jones)
(11423, 15907, 27144), -- 40680 (Stormwind Soldier)
(11305, 15756, 27144), -- 39887 (Captain Taylor)
(11421, 15904, 27144), -- 40664 (Recovering Soldier)
(20916, 31502, 27843), -- 29712 (Stormwind Harbor Guard)
(20920, 31498, 27843), -- 29712 (Stormwind Harbor Guard)
(20917, 17200, 27843), -- 29712 (Stormwind Harbor Guard)
(20922, 31499, 27843), -- 29712 (Stormwind Harbor Guard)
(20919, 31500, 27843), -- 29712 (Stormwind Harbor Guard)
(19861, 29496, 27843), -- 108750 (Eunna Young)
(20486, 30648, 27843), -- 107934 (Recruiter Lee)
(19930, 29609, 27843), -- 109412 (Lorcan Flintedge)
(17030, 24847, 27843), -- 86065 (Private Tristan)
(16856, 24513, 27843), -- 84285 (Jarrod Hamby)
(18712, 27197, 27602), -- 93812 (Salty Jorren)
(18418, 26553, 27602), -- 91968 (Amber Kearnen)
(18337, 26390, 27602), -- 91968 (Amber Kearnen)
(18417, 26552, 27602), -- 91968 (Amber Kearnen)
(18336, 26391, 27602), -- 91968 (Amber Kearnen)
(18226, 26179, 27602), -- 90584 (Goi'orsh)
(18225, 26180, 27602), -- 90584 (Goi'orsh)
(18328, 26381, 27602), -- 91935 (Exarch Maladaar)
(18511, 26760, 27602), -- 90967 (Kirin Tor Magus)
(18258, 26254, 27602), -- 90955 (Lion's Watch Rifleman)
(18257, 26253, 27602), -- 90955 (Lion's Watch Rifleman)
(18949, 27661, 27602), -- 99180 (Kluk'kluk)
(18582, 26939, 27602), -- 90963 (Angar Steelbellow)
(18582, 26940, 27602), -- 90963 (Angar Steelbellow)
(18387, 26487, 27602), -- 92545 (Norman Powerspark)
(18948, 27660, 27602), -- 99183 (Renegade Ironworker)
(16242, 23484, 27547), -- 76204 (Fiona)
(16549, 24035, 27547), -- 80635 (Rangari Arepheon)
(16551, 24037, 27547), -- 80761 (Beezil Linkspanner)
(16543, 24026, 27547), -- 80865 (Tarenar Sunstrike)
(16545, 24031, 27547), -- 80727 (Rangari Arepheon)
(16663, 24202, 27547), -- 82213 (Brighteye)
(16550, 24036, 27547), -- 81110 (Rangari Shaluua)
(16667, 24206, 27547), -- 82226 (Fey-Guardian Baashia)
(16661, 24200, 27547), -- 82211 (Fey-Guardian Scopas)
(16660, 24199, 27547), -- 82208 (Fey-Guardian Diunne)
(17533, 24926, 27547), -- 82487 (Shelly Hamby)
(16024, 23115, 27547), -- 74193 (Dead Packmule)
(16023, 23114, 27547), -- 223720
(16110, 23214, 27547), -- 224229
(16940, 24652, 27547), -- 84966 (Arcanist Delath)
(16942, 24654, 27547), -- 84966 (Arcanist Delath)
(16136, 23259, 27547), -- 73425 (Rangari Veka)
(16424, 23799, 27547), -- 79522 (Prophet Velen)
(15997, 23064, 27547), -- 74877 (Yrel)
(16442, 23763, 27547), -- 74877 (Yrel)
(15997, 23763, 27547), -- 74877 (Yrel)
(16395, 23763, 27547), -- 74877 (Yrel)
(16396, 23763, 27547), -- 74877 (Yrel)
(16134, 23258, 27547), -- 74121 (Loreseeker Heidii)
(16144, 23275, 27547), -- 224707
(16144, 23274, 27547), -- 224705
(16144, 23273, 27547), -- 224708
(16144, 23272, 27547); -- 224706

INSERT INTO `gossip_menu` (`MenuId`, `TextId`, `VerifiedBuild`) VALUES
(16979, 24716, 27547), -- 85645 (Gara)
(16016, 23104, 27547), -- 74164 (Iron Horde Propaganda)
(16014, 23102, 27547), -- 74164 (Iron Horde Propaganda)
(16015, 23103, 27547), -- 74164 (Iron Horde Propaganda)
(16375, 23739, 27547), -- 78789 (Shadowmoon Darkcaster)
(16017, 23105, 27547), -- 74164 (Iron Horde Propaganda)
(16012, 23100, 27547), -- 74164 (Iron Horde Propaganda)
(15979, 23012, 27547), -- 72638 (Quartermaster Thurg)
(15860, 23845, 27547), -- 73106 (Sylene)
(16454, 23850, 27547), -- 71641 (Old Loola)
(15262, 21875, 27377), -- 68275 (Hilda Hornswaggle)
(15174, 21750, 27377), -- 67558 (Huntsman Blake)
(15336, 22007, 27377), -- 67848 (Seamus Goldenkicks)
(15338, 22014, 27377), -- 68741 (Fennie Hornswaggle)
(15259, 21872, 27377), -- 67630 (Mishka)
(15258, 21871, 27377), -- 67631 (Marshal Troteman)
(15212, 21809, 27377), -- 67881 (Proveditor Grantley)
(15303, 21928, 27377), -- 68312 (Hilda Hornswaggle)
(15302, 21927, 27377), -- 68331 (Marshal Troteman)
(15764, 22647, 27377), -- 58919 (Anji Autumnlight)
(14955, 19719, 27377), -- 66386 (Mishi)
(16509, 23979, 27377), -- 80633 (Lorewalker Han)
(16370, 23714, 27377), -- 78777 (Lorewalker Shin)
(16364, 23711, 27377), -- 78709 (Lorewalker Fu)
(13829, 19965, 27377), -- 61962 (Lorewalker Cho)
(13829, 20652, 27377), -- 61962 (Lorewalker Cho)
(14357, 20269, 27377), -- 63984 (Master Liu)
(14362, 20276, 27377), -- 63983 (Ms. Thai)
(14615, 20676, 27377), -- 64922 (Brann Bronzebeard)
(15545, 22338, 27377), -- 70171 (Elloric)
(14409, 20335, 27377), -- 64287 (Summer)
(15967, 22992, 27377), -- 11704 (Kriss Goldenlight)
(14582, 20619, 27377), -- 64691 (Lorewalker Huynh)
(15958, 22981, 27377), -- 73691 (Chromie)
(15152, 933, 27377), -- 64153 (Coincounter Cammi)
(14404, 20330, 27377), -- 64073 (Andrea Toyas)
(14826, 20986, 27377), -- 64161 (Jonathan Le Karf)
(14558, 20579, 27377), -- 64124 (Kata Arina)
(14828, 20988, 27377), -- 64477 (Riverwarden Tuushuu)
(14827, 20987, 27377), -- 64476 (Poolwatcher Gui)
(14830, 20990, 27377), -- 64104 (Watershaper Sharu)
(10656, 20943, 27377), -- 65599 (H.A.R.V.E.Y.)
(15718, 22576, 27377), -- 64101 (Taijing the Cyclone)
(14802, 20947, 27377), -- 64150 (Master Zhang)
(14803, 20948, 27377), -- 64152 (Kiang Redwhisker)
(14809, 20959, 27377), -- 64157 (Vamuu)
(15956, 22974, 27377), -- 64154 (Historian Jenji)
(14818, 20970, 27377), -- 64172 (Advisor Kosa)
(14566, 20589, 27377), -- 64159 (Armorer Kisha)
(14810, 20960, 27377), -- 64156 (Hans Shuffleshoe)
(14808, 20957, 27377), -- 64155 (Historian Winterfur)
(14825, 20985, 27377), -- 64478 (Aqualyte Shashin)
(14829, 20989, 27377), -- 64102 (Seeker Arusshi)
(15952, 22968, 27377), -- 64100 (Meng Chi the Fist)
(14680, 11714, 27377), -- 64149 (Matron Vi Vinh)
(14804, 20949, 27377), -- 64142 (Jafu Windsword)
(14806, 20950, 27377), -- 64143 (Kressu)
(14805, 20951, 27377), -- 64143 (Kressu)
(14833, 20993, 27377), -- 64141 (Merra Finklestorm)
(14690, 21000, 27377), -- 64141 (Merra Finklestorm)
(14801, 20946, 27377), -- 64148 (Fitz Togglescrew)
(13648, 19608, 27377), -- 59961 (Kuru the Light-Hearted)
(15690, 22539, 27377), -- 71336 (Gleep Chatterswitch)
(15105, 21615, 27377), -- 64572 (Sara Finkleswitch)
(15107, 21614, 27377), -- 64572 (Sara Finkleswitch)
(15977, 23008, 27377), -- 64115 (Scott Smith)
(15148, 23007, 27377), -- 64072 (Omar Gonzalez)
(14794, 20917, 27377), -- 64030 (Lao Lang)
(14518, 20527, 27377), -- 64030 (Lao Lang)
(14346, 20255, 27377), -- 64030 (Lao Lang)
(14517, 20528, 27377), -- 64030 (Lao Lang)
(14793, 20916, 27377), -- 64488 (Riki the Shifting Shadow)
(14523, 20534, 27377), -- 64488 (Riki the Shifting Shadow)
(14522, 20532, 27377), -- 64488 (Riki the Shifting Shadow)
(14524, 20533, 27377), -- 64488 (Riki the Shifting Shadow)
(13651, 19580, 27377), -- 59908 (Jaluu the Generous)
(14792, 20918, 27377), -- 64031 (Xari the Kind)
(14514, 20524, 27377), -- 64031 (Xari the Kind)
(14347, 20256, 27377), -- 64031 (Xari the Kind)
(14515, 20525, 27377), -- 64031 (Xari the Kind)
(14348, 20257, 27377), -- 64032 (Sage Whiteheart)
(14512, 20519, 27377), -- 64032 (Sage Whiteheart)
(14513, 20520, 27377), -- 64032 (Sage Whiteheart)
(14510, 20517, 27377), -- 64029 (Elder Lin)
(14791, 20915, 27377), -- 64484 (Instructor Windspear)
(14508, 20515, 27377), -- 64484 (Instructor Windspear)
(14507, 20514, 27377), -- 64484 (Instructor Windspear)
(14509, 20516, 27377), -- 64484 (Instructor Windspear)
(14504, 20511, 27377), -- 64028 (Challenger Soong)
(14790, 20914, 27377), -- 64036 (Tang Ironhoe)
(14505, 20512, 27377), -- 64036 (Tang Ironhoe)
(14350, 20259, 27377), -- 64036 (Tang Ironhoe)
(14506, 20513, 27377), -- 64036 (Tang Ironhoe)
(14789, 20912, 27377), -- 64033 (Master Angler Marina)
(14503, 20510, 27377), -- 64033 (Master Angler Marina)
(14349, 20258, 27377), -- 64033 (Master Angler Marina)
(14502, 20509, 27377), -- 64033 (Master Angler Marina)
(14495, 20502, 27377), -- 64037 (Kichi of the Hundred Kegs)
(14351, 20260, 27377), -- 64037 (Kichi of the Hundred Kegs)
(14494, 20501, 27377), -- 64037 (Kichi of the Hundred Kegs)
(14788, 20921, 27377), -- 64508 (Scrollmaker Resshi)
(14520, 20531, 27377), -- 64508 (Scrollmaker Resshi)
(14519, 20529, 27377), -- 64508 (Scrollmaker Resshi)
(14521, 20530, 27377), -- 64508 (Scrollmaker Resshi)
(14819, 19719, 27377), -- 65716 (Mishi)
(14574, 20605, 27377), -- 64610 (Lyalia)
(14576, 20607, 27377), -- 64614 (Alynna Whisperblade)
(14575, 20606, 27377), -- 64613 (Magister Xintar)
(14692, 20843, 27377), -- 64117 (Soignera Strongbow)
(14751, 20844, 27377), -- 64117 (Soignera Strongbow)
(14752, 20845, 27377), -- 64117 (Soignera Strongbow)
(14693, 20821, 27377), -- 64117 (Soignera Strongbow)
(14771, 20865, 27377), -- 64117 (Soignera Strongbow)
(14750, 20841, 27377), -- 64117 (Soignera Strongbow)
(14749, 20840, 27377), -- 64117 (Soignera Strongbow)
(14748, 20839, 27377), -- 64117 (Soignera Strongbow)
(14747, 20838, 27377), -- 64117 (Soignera Strongbow)
(14746, 20837, 27377), -- 64117 (Soignera Strongbow)
(14745, 20836, 27377), -- 64117 (Soignera Strongbow)
(14744, 20835, 27377), -- 64117 (Soignera Strongbow)
(14743, 20834, 27377), -- 64117 (Soignera Strongbow)
(14742, 20833, 27377), -- 64117 (Soignera Strongbow)
(14770, 20864, 27377), -- 64117 (Soignera Strongbow)
(14741, 20832, 27377), -- 64117 (Soignera Strongbow)
(14740, 20831, 27377), -- 64117 (Soignera Strongbow)
(14739, 20830, 27377), -- 64117 (Soignera Strongbow)
(14738, 20829, 27377), -- 64117 (Soignera Strongbow)
(14737, 20828, 27377), -- 64117 (Soignera Strongbow)
(14736, 20827, 27377), -- 64117 (Soignera Strongbow)
(14735, 20825, 27377), -- 64117 (Soignera Strongbow)
(14697, 20826, 27377), -- 64117 (Soignera Strongbow)
(14696, 20824, 27377), -- 64117 (Soignera Strongbow)
(14695, 20823, 27377), -- 64117 (Soignera Strongbow)
(14694, 20822, 27377), -- 64117 (Soignera Strongbow)
(14691, 20820, 27377), -- 64117 (Soignera Strongbow)
(14772, 20908, 27377), -- 64117 (Soignera Strongbow)
(14785, 20914, 27377), -- 64117 (Soignera Strongbow)
(14784, 20917, 27377), -- 64117 (Soignera Strongbow)
(14783, 20915, 27377), -- 64117 (Soignera Strongbow)
(14782, 20921, 27377), -- 64117 (Soignera Strongbow)
(14781, 20916, 27377), -- 64117 (Soignera Strongbow)
(14780, 20918, 27377), -- 64117 (Soignera Strongbow)
(14778, 20919, 27377), -- 64117 (Soignera Strongbow)
(14776, 20912, 27377), -- 64117 (Soignera Strongbow)
(14775, 20911, 27377), -- 64117 (Soignera Strongbow)
(14831, 20991, 27377), -- 64117 (Soignera Strongbow)
(14774, 20910, 27377), -- 64117 (Soignera Strongbow)
(14773, 20909, 27377), -- 64117 (Soignera Strongbow)
(14769, 20846, 27377), -- 64117 (Soignera Strongbow)
(14768, 20862, 27377), -- 64117 (Soignera Strongbow)
(14767, 20861, 27377), -- 64117 (Soignera Strongbow)
(14766, 20860, 27377), -- 64117 (Soignera Strongbow)
(14765, 20859, 27377), -- 64117 (Soignera Strongbow)
(14764, 20858, 27377), -- 64117 (Soignera Strongbow)
(14763, 20857, 27377), -- 64117 (Soignera Strongbow)
(14761, 20856, 27377), -- 64117 (Soignera Strongbow)
(14762, 20855, 27377), -- 64117 (Soignera Strongbow)
(14754, 20848, 27377), -- 64117 (Soignera Strongbow)
(14760, 20854, 27377), -- 64117 (Soignera Strongbow)
(14759, 20853, 27377), -- 64117 (Soignera Strongbow)
(14758, 20852, 27377), -- 64117 (Soignera Strongbow)
(14756, 20851, 27377), -- 64117 (Soignera Strongbow)
(14757, 20850, 27377), -- 64117 (Soignera Strongbow)
(14755, 20849, 27377), -- 64117 (Soignera Strongbow)
(14689, 20819, 27377), -- 64117 (Soignera Strongbow)
(14688, 20818, 27377), -- 64117 (Soignera Strongbow)
(14686, 20816, 27377), -- 64117 (Soignera Strongbow)
(14561, 20583, 27377), -- 64117 (Soignera Strongbow)
(15127, 21694, 27377), -- 66245 (Mount-haver Nik Nik)
(14469, 20412, 27377), -- 58819 (Mayor Shiyo)
(15050, 21285, 27377), -- 66741 (Aki the Chosen)
(14457, 20398, 27377), -- 58818 (Cook Tope)
(14471, 20414, 27377), -- 58820 (Merchant Benny)
(15765, 22648, 27377), -- 58920 (Kun Autumnlight)
(14630, 20691, 27377), -- 65129 (Zen Master Lao)
(14470, 20413, 27377), -- 59341 (Merchant Tantan)
(14459, 20400, 27377), -- 58962 (Hai-Me Heavyhands)
(14482, 20425, 27377), -- 58743 (Yumi Goldenpaw)
(13438, 19128, 27377), -- 58704 (Kelari Featherfoot)
(13686, 19636, 27377), -- 59894 (Brother Yakshoe)
(13685, 19634, 27377), -- 59452 (Brother Rabbitsfoot)
(13638, 19974, 27377), -- 59696 (Uncle Cloverleaf)
(13638, 19556, 27377), -- 59696 (Uncle Cloverleaf)
(13637, 19555, 27377), -- 59695 (Big Sal)
(13645, 19571, 27377), -- 59716 (Ji-Lu the Lucky)
(13635, 19552, 27377), -- 59688 (Chiyo Mistpaw)
(13691, 19656, 27377), -- 59818 (Hiding Guide)
(13692, 19655, 27377), -- 59818 (Hiding Guide)
(13636, 19554, 27377), -- 59691 (Alchemist Yuan)
(13644, 19568, 27377), -- 59827 (Ironshaper Shou)
(13727, 19724, 27377), -- 59701 (Brother Lintpocket)
(13591, 19414, 27377), -- 59597 (Smokey Sootassle)
(13554, 19342, 27377), -- 59402 (Slimy Inkstain)
(13671, 19616, 27377), -- 59371 (Lucky Eightcoins)
(13786, 19870, 27377), -- 61488 (Hackiss)
(13784, 19868, 27377), -- 61490 (Tankiss)
(13852, 20018, 27377), -- 59371 (Lucky Eightcoins)
(13851, 20017, 27377), -- 59371 (Lucky Eightcoins)
(15540, 22331, 27377), -- 70155 (Griftah)
(14526, 20536, 27377), -- 64515 (Mystic Birdhat)
(14525, 20535, 27377), -- 64516 (Cousin Slowhands)
(14528, 20538, 27377), -- 64518 (Uncle Bigpocket)
(14605, 20663, 27377), -- 64882 (Madam Lani)
(13789, 19876, 27377), -- 61494 (Brewmaster Chani)
(13545, 19330, 27377), -- 59354 (Muskpaw Jr.)
(13544, 19325, 27377), -- 59353 (Lao Muskpaw)
(13545, 19328, 27377), -- 59354 (Muskpaw Jr.)
(13544, 19323, 27377), -- 59353 (Lao Muskpaw)
(13544, 19324, 27377), -- 59353 (Lao Muskpaw)
(14855, 21033, 27377), -- 63754 (Farmhand Bo)
(14868, 21026, 27377), -- 63542 (Elder Tsulan)
(14855, 21015, 27377), -- 63754 (Farmhand Bo)
(14868, 21024, 27377), -- 63542 (Elder Tsulan)
(13783, 19915, 27377), -- 60973 (Waterspeaker Gorai)
(13806, 19908, 27377), -- 59273 (Swordmistress Mei)
(13805, 19904, 27377), -- 59263 (Merchant Shi)
(13744, 19769, 27377), -- 59272 (Wu-Peng)
(13783, 19867, 27377), -- 60973 (Waterspeaker Gorai)
(13803, 19894, 27377), -- 61566 (Inkgill Dissenter)
(13806, 19909, 27377), -- 59273 (Swordmistress Mei)
(14800, 20941, 27377), -- 59077 (Apothecary Cheng)
(15116, 21631, 27377), -- 59073 (Mayor Bramblestaff)
(14531, 20548, 27377), -- 64521 (Wanderer Chu)
(14530, 20547, 27377), -- 64521 (Wanderer Chu)
(14532, 20539, 27377), -- 64521 (Wanderer Chu)
(14367, 20282, 27377), -- 63367 (Brewmaster Boof)
(14368, 20283, 27377), -- 64012 (Egg Shell)
(13229, 18648, 27366), -- 56066 (Bellmaster Li)
(13580, 19398, 27366), -- 59569 (Brewmaster Blanche)
(14447, 20385, 27366), -- 64384 (Mistweaver Lian)
(14451, 20390, 27366), -- 64394 (Mistweaver Chun)
(14450, 20388, 27366), -- 64382 (Thunderpaw Initiate)
(13247, 18663, 27366), -- 56315 (Jinyu Captive)
(13067, 19872, 27366), -- 55009 (Shao the Defiant)
(13067, 19873, 27366), -- 55009 (Shao the Defiant)
(13067, 18351, 27366), -- 55009 (Shao the Defiant)
(13561, 19355, 27366), -- 55209 (Traumatized Nectarbreeze Farmer)
(13104, 18409, 27366), -- 54854 (Gentle Mother Hanae)
(13561, 19354, 27366), -- 55209 (Traumatized Nectarbreeze Farmer)
(13074, 18360, 27366), -- 54697 (Shao the Defiant)
(13044, 18319, 27366), -- 54763 (Nectarbreeze Farmer)
(13104, 18408, 27366), -- 54854 (Gentle Mother Hanae)
(14428, 20353, 27366), -- 64311 (Overlook Watcher)
(13646, 19573, 27366), -- 59899 (Fei)
(14429, 20360, 27366), -- 59418 (Lorewalker Cho)
(14381, 20278, 27366), -- 64244 (Mishi)
(14364, 20278, 27366), -- 64475 (Mishi)
(13606, 19331, 27366), -- 59620 (Lorewalker Cho)
(13592, 19415, 27366), -- 59563 (Amber Kearnen)
(13579, 19396, 27366); -- 59550 (Sully "The Pickle" McLeary)

INSERT INTO `gossip_menu` (`MenuId`, `TextId`, `VerifiedBuild`) VALUES
(13605, 19472, 27366), -- 59619 (Mishka)
(13581, 19400, 27366), -- 59572 (Pearlfin Recruit)
(13228, 19308, 27366), -- 62107 (Bold Karasshi)
(13266, 19309, 27366), -- 55122 (Admiral Taylor)
(13250, 19306, 27366), -- 54960 (Elder Lusshan)
(13122, 18460, 27366), -- 55284 (Little Lu)
(13509, 19254, 27366), -- 59058 (Pearlkeeper Fujin)
(13281, 18777, 27366), -- 56693 (Ot-Temmdo)
(13605, 18718, 27366), -- 59619 (Mishka)
(13324, 18873, 27366), -- 57242 (Elder Sage Wind-Yi)
(13370, 18970, 27366), -- 57319 (Elder Sage Storm-Sing)
(13558, 19345, 27366), -- 57314 (Sage Ja-Ro)
(13302, 18875, 27366), -- 56784 (Fei)
(13304, 18814, 27366), -- 56782 (Elder Sage Rain-Zhu)
(13302, 18811, 27366), -- 56784 (Fei)
(13323, 18868, 27366), -- 56786 (Lorewalker Stonestep)
(13323, 18869, 27366), -- 56786 (Lorewalker Stonestep)
(13325, 18874, 27366), -- 56836 (Elder Sage Thunder-Lei)
(13303, 18813, 27366), -- 56787 (Wise Mari)
(13303, 18812, 27366), -- 56787 (Wise Mari)
(13324, 18876, 27366), -- 57242 (Elder Sage Wind-Yi)
(13372, 18976, 27366), -- 58162 (Master Tao Woodear)
(13371, 18973, 27366), -- 57313 (Fela Woodear)
(13340, 18895, 27366), -- 57324 (Elder Sage Tai-Feng)
(13881, 20066, 27366), -- 62642 (Chunhua the Spinning Blossom)
(13368, 18969, 27366), -- 57441 (Serpent Rider Kano)
(13550, 19336, 27366), -- 59392 (Kitemaster Shoku)
(13548, 19334, 27366), -- 59391 (Foreman Raike)
(13551, 19337, 27366), -- 59397 (Taskmaster Emi)
(13553, 19341, 27366), -- 59401 (Surveyor Sawa)
(13549, 19335, 27366), -- 59395 (Historian Dinh)
(13557, 19338, 27366), -- 59386 (Serpent Stonecarver)
(14941, 21121, 27366), -- 58414 (San Redscale)
(13434, 19111, 27366), -- 58531 (Toudu Tigerclaw)
(13396, 19025, 27366), -- 58225 (Instructor Tong)
(13401, 19040, 27366), -- 58225 (Instructor Tong)
(14445, 20383, 27366), -- 64371 (Kar)
(14446, 20384, 27366), -- 64376 (Rusty Nail)
(13100, 18397, 27366), -- 54922 (Master Stone Fist)
(13103, 18405, 27366), -- 54915 (Groundskeeper Wu)
(15123, 21653, 27366), -- 67096 (Nimble Shou)
(13058, 18337, 27366), -- 54926 (Xiao)
(13054, 18333, 27366), -- 54924 (Zhi-Zhi)
(13057, 18336, 27366), -- 54925 (Husshun)
(13059, 18338, 27366), -- 54944 (Tian Pupil)
(13072, 18358, 27366), -- 54914 (High Elder Cloudfall)
(13070, 18356, 27366), -- 54914 (High Elder Cloudfall)
(13105, 18411, 27366), -- 54913 (Lin Tenderpaw)
(13101, 18398, 27366), -- 54917 (Instructor Xann)
(13106, 18412, 27366), -- 54913 (Lin Tenderpaw)
(13572, 19386, 27366), -- 59492 (Pei-Zhi)
(13157, 19372, 27366), -- 55614 (Pei-Zhi)
(13564, 19367, 27366), -- 56346 (Foreman Mann)
(13564, 19891, 27366), -- 56346 (Foreman Mann)
(13563, 19365, 27366), -- 56345 (Lorewalker Cho)
(13565, 19369, 27366), -- 56467 (Hao Mann)
(13564, 19366, 27366), -- 56346 (Foreman Mann)
(13563, 19364, 27366), -- 56345 (Lorewalker Cho)
(14624, 20685, 27366), -- 65092 (Smeltmaster Ashpaw)
(13563, 19362, 27366), -- 56345 (Lorewalker Cho)
(14443, 20376, 27366), -- 64326 (Anglers Fisherwoman)
(14620, 20681, 27366), -- 64994 (Go Go)
(14442, 20375, 27366), -- 64324 (Anglers Fisherman)
(14649, 19889, 27366), -- 62321 (Brewmaster Tzu)
(14626, 20687, 27366), -- 65114 (Len the Hammer)
(14625, 20686, 27366), -- 65098 (Mai the Jade Shaper)
(13226, 18643, 27366), -- 56209 (Pandriarch Bramblestaff)
(13225, 18646, 27366), -- 56206 (Pandriarch Windfur)
(13227, 18644, 27366), -- 56210 (Pandriarch Goldendraft)
(13185, 18585, 27366), -- 55788 (Lo Wanderbrew)
(13432, 19097, 27366), -- 58510 (Suchi the Sweet)
(13430, 19095, 27366), -- 58509 (Ningna Darkwheel)
(13422, 19077, 27366), -- 58420 (Instructor Windblade)
(13291, 18794, 27366), -- 56065 (Inkmaster Wei)
(13808, 19912, 27366), -- 61640 (Chef Kyel)
(13433, 19098, 27366), -- 58413 (Jenova Longeye)
(14653, 20727, 27366), -- 58564 (Elder Anli)
(13427, 19091, 27366), -- 58564 (Elder Anli)
(13397, 19108, 27366), -- 58228 (Instructor Skythorn)
(13429, 19094, 27366), -- 58508 (Big Bao)
(13431, 19096, 27366), -- 58511 (Qua-Ro Whitebrow)
(13286, 18789, 27366), -- 56348 (Toya)
(13525, 19273, 27366), -- 56348 (Toya)
(13530, 20212, 27366), -- 59173 (Kai Wanderbrew)
(13132, 18473, 27366), -- 56659 (Shin)
(13137, 18478, 27366), -- 55368 (Widow Greenpaw)
(13110, 18523, 27366), -- 55274 (An Windfur)
(13109, 18422, 27366), -- 55267 (Scared Pandaren Cub)
(13132, 18825, 27366), -- 55451 (Shin)
(13129, 18470, 27366), -- 55401 (Master Greenpaw)
(13150, 18424, 27366), -- 55274 (An Windfur)
(13208, 18614, 27366), -- 56032 (General Rik-Rik Jr)
(13552, 19339, 27366), -- 59400 (Kitemaster Inga)
(15045, 21280, 27366), -- 66730 (Hyuna of the Shrines)
(13288, 18792, 27356), -- 54998 (Apprentice Yufi)
(13547, 19332, 27356), -- 59383 (Old Man Misteye)
(14312, 20207, 27356), -- 59160 (Master Windfur)
(13296, 20183, 27356), -- 56768 (Dawn Watcher)
(13297, 18804, 27356), -- 56776 (Pan)
(13299, 18806, 27356), -- 56774 (Bolo)
(13298, 18805, 27356), -- 56775 (Lee)
(13374, 20209, 27356), -- 55809 (Peiji Goldendraft)
(13283, 18786, 27356), -- 56707 (Chin)
(13782, 19863, 27356), -- 56778 (Yol)
(13284, 18787, 27356), -- 56062 (Tzu the Ironbelly)
(14628, 20689, 27356), -- 56777 (Ni Gentlepaw)
(13530, 19277, 27356), -- 59173 (Kai Wanderbrew)
(14309, 20199, 27356), -- 63577 (Lorewalker Cho)
(13286, 20181, 27356), -- 56348 (Toya)
(13538, 19293, 27356), -- 56737 (Ut-Nam)
(13254, 18702, 27356), -- 56434 (Anduin Wrynn)
(13255, 18703, 27356), -- 56432 (Ren Whitepaw)
(13256, 18704, 27356), -- 56433 (Lina Whitepaw)
(13236, 18577, 27356), -- 56267 (Lorewalker Cho)
(13531, 18577, 27356), -- 56287 (Lorewalker Cho)
(14402, 20328, 27356), -- 56287 (Lorewalker Cho)
(14401, 20327, 27356), -- 61218 (Lorewalker Cho)
(14280, 20127, 27356), -- 211661
(14410, 20336, 27356), -- 64295 (Autumn)
(13250, 19305, 27356), -- 54960 (Elder Lusshan)
(13541, 19311, 27356), -- 59348 (Pearlfin Villager)
(13266, 18721, 27356), -- 60970 (Admiral Taylor)
(13272, 18737, 27356), -- 56585 (Pearlfin Aqualyte)
(13274, 18739, 27356), -- 56592 (Pearlfin Aqualyte)
(13273, 18738, 27356), -- 56591 (Pearlfin Aqualyte)
(13271, 18736, 27356), -- 54959 (Pearlfin Aqualyte)
(13265, 18720, 27356), -- 56227 (Mishka)
(13119, 18453, 27356), -- 55282 (Sully "The Pickle" McLeary)
(13130, 18471, 27356), -- 55283 (Amber Kearnen)
(13116, 18450, 27356), -- 55333 (Rell Nightwind)
(13228, 19307, 27356), -- 56222 (Bold Karasshi)
(13128, 18466, 27356), -- 55381 (Widow Greenpaw)
(13115, 18447, 27356), -- 55343 (Amber Kearnen)
(13265, 18718, 27356), -- 56227 (Mishka)
(13250, 19280, 27356), -- 54960 (Elder Lusshan)
(13250, 18684, 27356), -- 54960 (Elder Lusshan)
(13116, 18679, 27356), -- 66949 (Rell Nightwind)
(13228, 18647, 27356), -- 56222 (Bold Karasshi)
(13510, 19255, 27356), -- 56690 (Instructor Sharpfin)
(13509, 19924, 27356), -- 59058 (Pearlkeeper Fujin)
(13266, 18722, 27356), -- 60970 (Admiral Taylor)
(13122, 18677, 27356), -- 55284 (Little Lu)
(13809, 19913, 27356), -- 61599 (Cheerful Jessu)
(13541, 19310, 27356), -- 59348 (Pearlfin Villager)
(13274, 18741, 27356), -- 56592 (Pearlfin Aqualyte)
(13272, 18741, 27356), -- 56585 (Pearlfin Aqualyte)
(13502, 19235, 27356), -- 55196 (Bold Karasshi)
(13502, 19237, 27356), -- 55196 (Bold Karasshi)
(13503, 19238, 27356), -- 59022 (Admiral Taylor)
(13502, 19241, 27356), -- 55196 (Bold Karasshi)
(13117, 18451, 27356), -- 54615 (Nodd Codejack)
(15112, 21624, 27356), -- 65910 (Sunke Khang)
(14971, 21622, 27356), -- 66292 (Sky Admiral Rogers)
(13518, 19264, 27356), -- 54618 (Nimm Codejack)
(13313, 18838, 27356), -- 54616 (Sully "The Pickle" McLeary)
(14990, 21266, 27356), -- 54617 (Rell Nightwind)
(13312, 18835, 27356), -- 54614 (Mishka)
(15112, 21623, 27356), -- 65910 (Sunke Khang)
(14943, 21124, 27356), -- 66032 (Watcher Jo Lin)
(14942, 21123, 27356), -- 66031 (Elder Daelo)
(14921, 21092, 27356), -- 65917 (Cui Applebloom)
(14920, 21091, 27356), -- 65908 (Seer Yong)
(14919, 21090, 27356), -- 65927 (Chut Sri Nu)
(14918, 21089, 27356), -- 65927 (Chut Sri Nu)
(14911, 21086, 27356), -- 65893 (Elder Yoon Su)
(14912, 21085, 27356), -- 65893 (Elder Yoon Su)
(14913, 21084, 27356), -- 65893 (Elder Yoon Su)
(15110, 21619, 27356), -- 64596 (Teng Applebloom)
(14935, 21114, 27356), -- 65907 (Jiayi Applebloom)
(14932, 21106, 27356), -- 65909 (Serenity)
(15099, 21500, 27356), -- 67025 (Orchard Keeper Li Mei)
(15100, 21501, 27356), -- 67026 (Hao of the Stag's Horns)
(14926, 21097, 27356), -- 65937 (Craftsman Hui)
(15098, 21499, 27356), -- 67024 (Rockseeker Guo)
(14990, 21203, 27356), -- 54617 (Rell Nightwind)
(14990, 21190, 27356), -- 54617 (Rell Nightwind)
(14971, 21617, 27356), -- 66292 (Sky Admiral Rogers)
(14971, 21166, 27356), -- 66292 (Sky Admiral Rogers)
(15111, 21620, 27356), -- 66292 (Sky Admiral Rogers)
(12134, 17045, 27326), -- 46513 (Initiate Goldmine)
(12133, 17042, 27326), -- 46243 (Initiate Goldmine)
(12154, 17089, 27326), -- 46413 (Countess Verrall)
(12098, 16986, 27326), -- 45796 (Master Mathias Shaw)
(12651, 17799, 27326), -- 46242 (Earthcaller Yevaa)
(12083, 16959, 27326), -- 46076 (SI:7 Squad Commander)
(12066, 16923, 27326), -- 45669 (Cassius the White)
(12060, 16908, 27326), -- 45904 (Angus Stillmountain)
(12253, 15104, 27326), -- 47611 (Highbank Lieutenant)
(12303, 17296, 27326), -- 47592 (Master Mathias Shaw)
(12070, 16938, 27326), -- 45528 (Calen)
(13246, 18672, 27326), -- 56314 (Mostrasz)
(13248, 18678, 27326), -- 56371 (Suspicious Infiltrator)
(13160, 18544, 27326), -- 55488 (Corastrasza)
(12021, 16847, 27326), -- 45332 (Earthcaller Torunscar)
(12020, 16846, 27326), -- 45432 (Initiate Goldmine)
(12465, 17534, 27326), -- 48367 (Lachlan MacGraff)
(12459, 17521, 27326), -- 48758 (Hammelhand)
(12451, 17513, 27326), -- 48366 (Russell Brower)
(12457, 17518, 27326), -- 48366 (Russell Brower)
(12456, 17517, 27326), -- 48366 (Russell Brower)
(12455, 17516, 27326), -- 48366 (Russell Brower)
(12427, 17472, 27326), -- 48472 (Colin Thundermar)
(12379, 17399, 27326), -- 48499 (Fanny Thundermar)
(12425, 17468, 27326), -- 48365 (Kurdran Wildhammer)
(12465, 17533, 27326), -- 48367 (Lachlan MacGraff)
(12480, 17557, 27326), -- 48368 (Grundy MacGraff)
(12425, 17467, 27326), -- 48365 (Kurdran Wildhammer)
(12409, 17443, 27326), -- 48173 (Colin Thundermar)
(12548, 17626, 27326), -- 50041 (Myzrael)
(15065, 21295, 27326), -- 66815 (Bordin Steadyfist)
(11920, 16736, 27326), -- 43405 (Mariahn the Soulcleanser)
(12003, 16825, 27326), -- 45300 (Caretaker Nuunwa)
(12446, 17503, 27291), -- 48621 (Sullah)
(12445, 17501, 27291), -- 48604 (Harrison Jones)
(12441, 17496, 27291), -- 48528 (Harrison Jones)
(12402, 17431, 27291), -- 48186 (Harrison Jones)
(12426, 17469, 27291), -- 48431 (Sullah)
(12499, 7727, 27291), -- 49406 (Yasmin)
(12591, 17710, 27291), -- 49410 (Aaron "Sandy Toes" Williamson)
(12405, 17434, 27291), -- 48203 (Sullah)
(12403, 17432, 27291), -- 47972 (Commander Schnottz)
(12368, 17372, 27291), -- 47965 (Privileged Socialite)
(12364, 17368, 27291), -- 47961 (Aspiring Starlet)
(12366, 17370, 27291), -- 47963 (Refined Gentleman)
(12367, 17371, 27291), -- 47964 (Pretentious Businessman)
(12365, 17369, 27291), -- 47962 (Budding Artist)
(12355, 17360, 27291), -- 47946 (Menacing Emissary)
(12354, 17359, 27291), -- 47940 (Commander Schnottz)
(12316, 17311, 27291), -- 47520 (Pretentious Businessman)
(12315, 17310, 27291), -- 47520 (Pretentious Businessman)
(12314, 17309, 27291), -- 47520 (Pretentious Businessman)
(12287, 17255, 27291), -- 47516 (Prolific Writer)
(12286, 17254, 27291), -- 47516 (Prolific Writer)
(12285, 17253, 27291), -- 47516 (Prolific Writer)
(12284, 17252, 27291), -- 47516 (Prolific Writer)
(12291, 17259, 27291), -- 47519 (Privileged Socialite)
(12290, 17258, 27291), -- 47519 (Privileged Socialite)
(12289, 17257, 27291), -- 47519 (Privileged Socialite)
(12288, 17256, 27291), -- 47519 (Privileged Socialite)
(12319, 17314, 27291), -- 47707 (Budding Artist)
(12318, 17313, 27291), -- 47707 (Budding Artist)
(12317, 17312, 27291), -- 47707 (Budding Artist)
(12320, 17315, 27291), -- 47708 (Aspiring Starlet)
(12313, 17308, 27291), -- 47703 (Refined Gentleman)
(12312, 17307, 27291), -- 47702 (Menacing Emissary)
(12310, 17305, 27291), -- 47515 (Ambassador Laurent)
(12213, 17192, 27291), -- 47159 (Commander Schnottz)
(12238, 17189, 27291), -- 47292 (Slacking Laborer)
(12038, 16868, 27291), -- 45514 (Wavespeaker Valoren)
(11852, 16614, 27291); -- 50259 (Captain Taylor)

INSERT INTO `gossip_menu` (`MenuId`, `TextId`, `VerifiedBuild`) VALUES
(11633, 16246, 27291), -- 41639 (Wavespeaker Tulra)
(11607, 16202, 27291), -- 42197 (L'ghorek)
(11535, 16105, 27291), -- 41666 (Engineer Hexascrub)
(11630, 16243, 27291), -- 41667 (Lieutenant "Foxy" Topper)
(11634, 16247, 27291), -- 41640 (Wavespeaker Valoren)
(11574, 16164, 27291), -- 41910 (Humphrey Digsong)
(11582, 16172, 27291), -- 41910 (Humphrey Digsong)
(11581, 16171, 27291), -- 41910 (Humphrey Digsong)
(11580, 16170, 27291), -- 41910 (Humphrey Digsong)
(11579, 16169, 27291), -- 41910 (Humphrey Digsong)
(11578, 16168, 27291), -- 41910 (Humphrey Digsong)
(11577, 16167, 27291), -- 41910 (Humphrey Digsong)
(11576, 16166, 27291), -- 41910 (Humphrey Digsong)
(11575, 16165, 27291), -- 41910 (Humphrey Digsong)
(11594, 16189, 27291), -- 203461
(11592, 16187, 27291), -- 203461
(11591, 16186, 27291), -- 203461
(11590, 16185, 27291), -- 203461
(11589, 16184, 27291), -- 203461
(11588, 16183, 27291), -- 203461
(11593, 16182, 27291), -- 203461
(11586, 16188, 27291), -- 203461
(11627, 16239, 27291), -- 41665 (Jorlan Trueblade)
(11572, 16149, 27291), -- 41980 (Fathom-Caller Azrajar)
(11571, 16147, 27291), -- 41985 (Sira'kess Tide Priestess)
(11477, 16014, 27291), -- 41535 (Engineer Hexascrub)
(11515, 16069, 27291), -- 42072 (Fathom-Lord Zin'jatar)
(11516, 16070, 27291), -- 41455 (Overseer Idra'kess)
(11517, 16071, 27291), -- 42071 (Lady Sira'kess)
(11481, 16019, 27291), -- 41281 (Injured Assault Volunteer)
(11849, 16610, 27291), -- 39881 (Wavespeaker Valoren)
(12603, 17741, 27291), -- 40644 (Levia Dreamwaker)
(12604, 17742, 27291), -- 39881 (Wavespeaker Valoren)
(11474, 16008, 27291), -- 40643 (Admiral Dvorek)
(11647, 16270, 27291), -- 39881 (Wavespeaker Valoren)
(11525, 16084, 27291), -- 41531 (Earthmender Duarn)
(11598, 16193, 27291), -- 41540 (Captain Taylor)
(11599, 16194, 27291), -- 41541 (Admiral Dvorek)
(11605, 16198, 27291), -- 41813 (Wavespeaker Tulra)
(11601, 16195, 27291), -- 41802 (Wavespeaker Valoren)
(11600, 16196, 27291), -- 41542 (Jorlan Trueblade)
(11400, 15880, 27291), -- 39875 (Earthmender Duarn)
(11399, 15878, 27291), -- 40221 (Toshe Chaosrender)
(11344, 15802, 27291), -- 39876 (Felora Firewreath)
(11352, 15818, 27291), -- 39882 (The Great Sambino)
(11350, 15820, 27291), -- 39882 (The Great Sambino)
(11351, 15819, 27291), -- 39882 (The Great Sambino)
(11538, 16108, 27291), -- 39878 (Caretaker Movra)
(11553, 16122, 27291), -- 41871 (Earthwatcher Komo)
(11554, 16125, 27291), -- 41878 (Earthwatcher Faldor)
(12370, 17374, 27291), -- 40851 (Swift Seahorse)
(11851, 16613, 27291), -- 39226 (Farseer Gadra)
(11608, 16203, 27291), -- 39226 (Farseer Gadra)
(17546, 24884, 27602), -- 85081 (Admiral Taylor)
(17557, 25291, 27602), -- 86760 (Talonpriest Ishaal)
(17104, 25148, 27602), -- 85619 (Yrel)
(17987, 25930, 27602), -- 89234 (Ancient Waygate Protector)
(16163, 23341, 27602), -- 75593 (Rooter)
(16343, 23662, 27602), -- 78192 (Choluna)
(16345, 23664, 27602), -- 78187 (Thisalee Crow)
(16727, 24322, 27602), -- 82302 (Birchus)
(16956, 24672, 27602), -- 85436 (Altauur)
(16955, 24670, 27602), -- 85431 (Altauur)
(16954, 24669, 27602), -- 85432 (Altauur)
(16665, 24204, 27602), -- 81723 (Birchus)
(16664, 24203, 27602), -- 81723 (Birchus)
(16662, 24201, 27602), -- 81723 (Birchus)
(16950, 24664, 27602), -- 85426 (Altauur)
(17106, 25150, 27602), -- 86491 (Rexxar)
(16619, 24143, 27602), -- 81751 (Hansel Heavyhands)
(16618, 24142, 27602), -- 75710 (Hansel Heavyhands)
(16717, 24294, 27602), -- 81589 (Rangari Kaalya)
(16716, 24293, 27602), -- 81590 (Yrel)
(16793, 24415, 27602), -- 83820 (High Centurion Tormmok)
(16791, 24417, 27602), -- 83820 (High Centurion Tormmok)
(16792, 24416, 27602), -- 83820 (High Centurion Tormmok)
(16608, 24129, 27602), -- 82381 (Scorchbrow)
(16329, 23643, 27602), -- 78030 (Blook)
(18867, 27478, 27602), -- 98224 (Lohor)
(16599, 24103, 27602), -- 81600 (Burrian Coalpart)
(16607, 24128, 27602), -- 81675 (Nori Sootstash)
(16605, 24125, 27602), -- 81676 (Lera Ashtoes)
(16777, 25433, 27602), -- 83837 (Cymre Brightblade)
(17203, 25434, 27602), -- 83837 (Cymre Brightblade)
(16686, 24237, 27602), -- 82493 (Sappy)
(16700, 24269, 27602), -- 82477 (Khaano)
(16699, 24268, 27602), -- 82476 (Khaano)
(16698, 24267, 27602), -- 82476 (Khaano)
(16562, 24057, 27602), -- 75146 (Rangari D'kaan)
(17021, 24833, 27602), -- 86043 (Rangari Jonaa)
(16895, 24573, 27602), -- 84766 (Glirin)
(16542, 24025, 27602), -- 81020 (Rangari Jonaa)
(16538, 24021, 27602), -- 81013 (Rangari Rajess)
(16539, 24022, 27602), -- 81018 (Rangari Kolaan)
(16562, 24059, 27602), -- 75146 (Rangari D'kaan)
(16523, 24002, 27602), -- 80921 (Rangari D'kaan)
(18538, 26811, 27602), -- 92213 (Archmage Khadgar)
(18486, 26743, 27602), -- 95002 (Yanas Seastrike)
(18189, 7778, 27602), -- 90188 (Taal Blevaans)
(16762, 24355, 27602), -- 83567 (Firn Swiftbreeze)
(16849, 24500, 27602), -- 84262 (Reshad)
(16703, 24288, 27602), -- 77857 (Ka'alu)
(17037, 24893, 27602), -- 86311 (High Ravenspeaker Krikka)
(16515, 23991, 27602), -- 80481 (High Ravenspeaker Krikka)
(17091, 25121, 27602), -- 80746 (Vakora of the Flock)
(16770, 24369, 27602), -- 80740 (Ravenspeaker Sekara)
(17246, 25520, 27602), -- 88045 (Zektar)
(16822, 24456, 27602), -- 84122 (Shade of Terokk)
(16822, 24458, 27602), -- 84122 (Shade of Terokk)
(16640, 25241, 27602), -- 80153 (Shadow-Sage Iskar)
(16737, 24337, 27602), -- 82813 (Effigy of Terokk)
(16651, 24187, 27602), -- 232167
(16946, 24656, 27602), -- 80232 (Talonpriest Ishaal)
(16502, 23966, 27602), -- 80233 (Skizzik)
(16876, 24540, 27602), -- 84504 (Skytalon Karaz)
(16978, 24715, 27602), -- 85614 (Anzu)
(16977, 24714, 27602), -- 85614 (Anzu)
(17282, 25592, 27602), -- 86475 (Talon Guard Kurekk)
(16854, 24510, 27602), -- 84261 (Kolrigg Stoktron)
(16817, 24451, 27602), -- 84104 (Riding Gryphon)
(16652, 24188, 27602), -- 82110 (Alice Finn)
(16860, 24519, 27602); -- 84332 (Rooby Roo)

DELETE FROM `gossip_menu_option` WHERE (`MenuId`=18491 AND `OptionIndex`=1) OR (`MenuId`=18326 AND `OptionIndex`=1) OR (`MenuId`=18488 AND `OptionIndex`=0) OR (`MenuId`=17051 AND `OptionIndex`=0) OR (`MenuId`=16872 AND `OptionIndex`=0) OR (`MenuId`=16707 AND `OptionIndex`=2) OR (`MenuId`=16877 AND `OptionIndex`=1) OR (`MenuId`=16718 AND `OptionIndex`=1) OR (`MenuId`=16718 AND `OptionIndex`=0) OR (`MenuId`=16283 AND `OptionIndex`=0) OR (`MenuId`=16597 AND `OptionIndex`=0) OR (`MenuId`=16897 AND `OptionIndex`=0) OR (`MenuId`=17055 AND `OptionIndex`=0) OR (`MenuId`=17431 AND `OptionIndex`=0) OR (`MenuId`=16864 AND `OptionIndex`=0) OR (`MenuId`=18201 AND `OptionIndex`=30) OR (`MenuId`=18201 AND `OptionIndex`=15) OR (`MenuId`=18201 AND `OptionIndex`=14) OR (`MenuId`=18201 AND `OptionIndex`=13) OR (`MenuId`=18201 AND `OptionIndex`=12) OR (`MenuId`=18201 AND `OptionIndex`=11) OR (`MenuId`=18201 AND `OptionIndex`=10) OR (`MenuId`=18201 AND `OptionIndex`=8) OR (`MenuId`=18201 AND `OptionIndex`=6) OR (`MenuId`=18268 AND `OptionIndex`=1) OR (`MenuId`=18268 AND `OptionIndex`=0) OR (`MenuId`=16811 AND `OptionIndex`=0) OR (`MenuId`=16514 AND `OptionIndex`=2) OR (`MenuId`=16595 AND `OptionIndex`=0) OR (`MenuId`=16829 AND `OptionIndex`=0) OR (`MenuId`=16825 AND `OptionIndex`=0) OR (`MenuId`=16823 AND `OptionIndex`=0) OR (`MenuId`=16586 AND `OptionIndex`=0) OR (`MenuId`=16423 AND `OptionIndex`=1) OR (`MenuId`=17317 AND `OptionIndex`=0) OR (`MenuId`=16894 AND `OptionIndex`=5) OR (`MenuId`=18287 AND `OptionIndex`=0) OR (`MenuId`=16916 AND `OptionIndex`=7) OR (`MenuId`=16452 AND `OptionIndex`=1) OR (`MenuId`=16452 AND `OptionIndex`=0) OR (`MenuId`=16728 AND `OptionIndex`=2) OR (`MenuId`=16728 AND `OptionIndex`=0) OR (`MenuId`=16514 AND `OptionIndex`=1) OR (`MenuId`=16514 AND `OptionIndex`=0) OR (`MenuId`=16492 AND `OptionIndex`=0) OR (`MenuId`=16494 AND `OptionIndex`=0) OR (`MenuId`=16653 AND `OptionIndex`=0) OR (`MenuId`=16732 AND `OptionIndex`=0) OR (`MenuId`=16904 AND `OptionIndex`=0) OR (`MenuId`=17357 AND `OptionIndex`=0) OR (`MenuId`=16467 AND `OptionIndex`=0) OR (`MenuId`=16416 AND `OptionIndex`=4) OR (`MenuId`=16416 AND `OptionIndex`=3) OR (`MenuId`=16416 AND `OptionIndex`=2) OR (`MenuId`=16416 AND `OptionIndex`=1) OR (`MenuId`=16416 AND `OptionIndex`=0) OR (`MenuId`=16569 AND `OptionIndex`=1) OR (`MenuId`=16569 AND `OptionIndex`=0) OR (`MenuId`=16570 AND `OptionIndex`=0) OR (`MenuId`=18167 AND `OptionIndex`=0) OR (`MenuId`=16721 AND `OptionIndex`=0) OR (`MenuId`=16597 AND `OptionIndex`=2) OR (`MenuId`=16650 AND `OptionIndex`=0) OR (`MenuId`=16875 AND `OptionIndex`=1) OR (`MenuId`=16875 AND `OptionIndex`=0) OR (`MenuId`=16832 AND `OptionIndex`=0) OR (`MenuId`=16640 AND `OptionIndex`=0) OR (`MenuId`=17043 AND `OptionIndex`=1) OR (`MenuId`=17043 AND `OptionIndex`=0) OR (`MenuId`=17201 AND `OptionIndex`=0) OR (`MenuId`=17107 AND `OptionIndex`=1) OR (`MenuId`=17107 AND `OptionIndex`=0) OR (`MenuId`=16476 AND `OptionIndex`=0) OR (`MenuId`=16575 AND `OptionIndex`=0) OR (`MenuId`=16597 AND `OptionIndex`=10) OR (`MenuId`=16597 AND `OptionIndex`=9) OR (`MenuId`=16597 AND `OptionIndex`=1) OR (`MenuId`=16688 AND `OptionIndex`=1) OR (`MenuId`=16688 AND `OptionIndex`=0) OR (`MenuId`=16597 AND `OptionIndex`=7) OR (`MenuId`=18677 AND `OptionIndex`=4) OR (`MenuId`=18677 AND `OptionIndex`=0) OR (`MenuId`=17531 AND `OptionIndex`=0) OR (`MenuId`=17422 AND `OptionIndex`=0) OR (`MenuId`=17306 AND `OptionIndex`=5) OR (`MenuId`=17306 AND `OptionIndex`=2) OR (`MenuId`=17306 AND `OptionIndex`=1) OR (`MenuId`=17306 AND `OptionIndex`=0) OR (`MenuId`=17319 AND `OptionIndex`=0) OR (`MenuId`=16998 AND `OptionIndex`=2) OR (`MenuId`=18322 AND `OptionIndex`=0) OR (`MenuId`=18566 AND `OptionIndex`=11) OR (`MenuId`=18566 AND `OptionIndex`=10) OR (`MenuId`=18566 AND `OptionIndex`=9) OR (`MenuId`=18566 AND `OptionIndex`=8) OR (`MenuId`=18566 AND `OptionIndex`=7) OR (`MenuId`=18566 AND `OptionIndex`=6) OR (`MenuId`=18566 AND `OptionIndex`=5) OR (`MenuId`=18566 AND `OptionIndex`=4) OR (`MenuId`=18566 AND `OptionIndex`=3) OR (`MenuId`=18566 AND `OptionIndex`=2) OR (`MenuId`=18566 AND `OptionIndex`=1) OR (`MenuId`=18566 AND `OptionIndex`=0) OR (`MenuId`=17330 AND `OptionIndex`=1) OR (`MenuId`=17330 AND `OptionIndex`=0) OR (`MenuId`=16518 AND `OptionIndex`=1) OR (`MenuId`=16518 AND `OptionIndex`=0) OR (`MenuId`=16641 AND `OptionIndex`=0) OR (`MenuId`=16863 AND `OptionIndex`=0) OR (`MenuId`=13843 AND `OptionIndex`=0) OR (`MenuId`=13831 AND `OptionIndex`=1) OR (`MenuId`=13831 AND `OptionIndex`=0) OR (`MenuId`=13836 AND `OptionIndex`=0) OR (`MenuId`=13830 AND `OptionIndex`=1) OR (`MenuId`=13830 AND `OptionIndex`=0) OR (`MenuId`=13678 AND `OptionIndex`=0) OR (`MenuId`=13681 AND `OptionIndex`=0) OR (`MenuId`=13680 AND `OptionIndex`=0) OR (`MenuId`=13794 AND `OptionIndex`=0) OR (`MenuId`=13795 AND `OptionIndex`=1) OR (`MenuId`=13795 AND `OptionIndex`=0) OR (`MenuId`=13720 AND `OptionIndex`=0) OR (`MenuId`=13893 AND `OptionIndex`=0) OR (`MenuId`=13892 AND `OptionIndex`=0) OR (`MenuId`=13796 AND `OptionIndex`=0) OR (`MenuId`=15055 AND `OptionIndex`=2) OR (`MenuId`=15055 AND `OptionIndex`=1) OR (`MenuId`=13686 AND `OptionIndex`=0) OR (`MenuId`=13467 AND `OptionIndex`=2) OR (`MenuId`=13467 AND `OptionIndex`=0) OR (`MenuId`=13462 AND `OptionIndex`=4) OR (`MenuId`=13462 AND `OptionIndex`=3) OR (`MenuId`=13462 AND `OptionIndex`=1) OR (`MenuId`=13464 AND `OptionIndex`=2) OR (`MenuId`=13464 AND `OptionIndex`=0) OR (`MenuId`=13745 AND `OptionIndex`=0) OR (`MenuId`=13301 AND `OptionIndex`=4) OR (`MenuId`=13301 AND `OptionIndex`=3) OR (`MenuId`=13301 AND `OptionIndex`=2) OR (`MenuId`=13437 AND `OptionIndex`=0) OR (`MenuId`=13301 AND `OptionIndex`=1) OR (`MenuId`=13301 AND `OptionIndex`=0) OR (`MenuId`=13310 AND `OptionIndex`=1) OR (`MenuId`=13310 AND `OptionIndex`=0) OR (`MenuId`=13318 AND `OptionIndex`=0) OR (`MenuId`=13317 AND `OptionIndex`=0) OR (`MenuId`=13320 AND `OptionIndex`=0) OR (`MenuId`=13316 AND `OptionIndex`=0) OR (`MenuId`=13311 AND `OptionIndex`=0) OR (`MenuId`=13748 AND `OptionIndex`=0) OR (`MenuId`=13747 AND `OptionIndex`=0) OR (`MenuId`=13746 AND `OptionIndex`=0) OR (`MenuId`=13424 AND `OptionIndex`=0) OR (`MenuId`=14795 AND `OptionIndex`=1) OR (`MenuId`=14795 AND `OptionIndex`=0) OR (`MenuId`=14324 AND `OptionIndex`=0) OR (`MenuId`=13379 AND `OptionIndex`=1) OR (`MenuId`=13378 AND `OptionIndex`=0) OR (`MenuId`=13398 AND `OptionIndex`=0) OR (`MenuId`=13622 AND `OptionIndex`=10) OR (`MenuId`=13622 AND `OptionIndex`=9) OR (`MenuId`=13622 AND `OptionIndex`=8) OR (`MenuId`=13622 AND `OptionIndex`=7) OR (`MenuId`=13622 AND `OptionIndex`=6) OR (`MenuId`=13622 AND `OptionIndex`=5) OR (`MenuId`=13622 AND `OptionIndex`=4) OR (`MenuId`=13622 AND `OptionIndex`=3) OR (`MenuId`=13622 AND `OptionIndex`=2) OR (`MenuId`=13622 AND `OptionIndex`=1) OR (`MenuId`=13470 AND `OptionIndex`=5) OR (`MenuId`=13470 AND `OptionIndex`=2) OR (`MenuId`=13470 AND `OptionIndex`=1) OR (`MenuId`=13470 AND `OptionIndex`=0) OR (`MenuId`=12135 AND `OptionIndex`=0) OR (`MenuId`=12136 AND `OptionIndex`=0) OR (`MenuId`=12137 AND `OptionIndex`=0) OR (`MenuId`=12138 AND `OptionIndex`=0) OR (`MenuId`=11522 AND `OptionIndex`=1) OR (`MenuId`=11522 AND `OptionIndex`=0) OR (`MenuId`=11489 AND `OptionIndex`=0) OR (`MenuId`=11514 AND `OptionIndex`=0) OR (`MenuId`=11510 AND `OptionIndex`=0) OR (`MenuId`=11511 AND `OptionIndex`=0) OR (`MenuId`=11508 AND `OptionIndex`=0) OR (`MenuId`=11509 AND `OptionIndex`=0) OR (`MenuId`=11444 AND `OptionIndex`=0) OR (`MenuId`=12213 AND `OptionIndex`=0) OR (`MenuId`=18536 AND `OptionIndex`=0) OR (`MenuId`=18486 AND `OptionIndex`=4) OR (`MenuId`=18486 AND `OptionIndex`=3) OR (`MenuId`=18486 AND `OptionIndex`=1) OR (`MenuId`=18253 AND `OptionIndex`=0) OR (`MenuId`=18599 AND `OptionIndex`=0) OR (`MenuId`=18437 AND `OptionIndex`=0) OR (`MenuId`=18335 AND `OptionIndex`=1) OR (`MenuId`=18335 AND `OptionIndex`=0) OR (`MenuId`=18331 AND `OptionIndex`=2) OR (`MenuId`=18331 AND `OptionIndex`=1) OR (`MenuId`=18331 AND `OptionIndex`=0) OR (`MenuId`=18333 AND `OptionIndex`=0) OR (`MenuId`=18412 AND `OptionIndex`=1) OR (`MenuId`=18412 AND `OptionIndex`=0) OR (`MenuId`=18620 AND `OptionIndex`=0) OR (`MenuId`=18228 AND `OptionIndex`=0) OR (`MenuId`=18670 AND `OptionIndex`=0) OR (`MenuId`=17542 AND `OptionIndex`=0) OR (`MenuId`=17038 AND `OptionIndex`=0) OR (`MenuId`=16353 AND `OptionIndex`=0) OR (`MenuId`=16367 AND `OptionIndex`=0) OR (`MenuId`=16357 AND `OptionIndex`=0) OR (`MenuId`=16312 AND `OptionIndex`=0) OR (`MenuId`=16448 AND `OptionIndex`=0) OR (`MenuId`=16447 AND `OptionIndex`=0) OR (`MenuId`=16692 AND `OptionIndex`=0) OR (`MenuId`=16850 AND `OptionIndex`=0) OR (`MenuId`=16814 AND `OptionIndex`=0) OR (`MenuId`=16878 AND `OptionIndex`=0) OR (`MenuId`=17094 AND `OptionIndex`=0) OR (`MenuId`=17321 AND `OptionIndex`=0) OR (`MenuId`=17541 AND `OptionIndex`=0) OR (`MenuId`=17443 AND `OptionIndex`=0) OR (`MenuId`=17511 AND `OptionIndex`=0) OR (`MenuId`=18498 AND `OptionIndex`=0) OR (`MenuId`=18497 AND `OptionIndex`=0) OR (`MenuId`=18492 AND `OptionIndex`=0) OR (`MenuId`=18489 AND `OptionIndex`=0) OR (`MenuId`=17183 AND `OptionIndex`=0) OR (`MenuId`=17148 AND `OptionIndex`=2) OR (`MenuId`=17148 AND `OptionIndex`=1) OR (`MenuId`=17148 AND `OptionIndex`=0) OR (`MenuId`=17182 AND `OptionIndex`=0) OR (`MenuId`=17152 AND `OptionIndex`=0) OR (`MenuId`=17153 AND `OptionIndex`=0) OR (`MenuId`=17157 AND `OptionIndex`=0) OR (`MenuId`=17131 AND `OptionIndex`=0) OR (`MenuId`=17130 AND `OptionIndex`=0) OR (`MenuId`=17334 AND `OptionIndex`=11) OR (`MenuId`=17334 AND `OptionIndex`=10) OR (`MenuId`=17334 AND `OptionIndex`=9) OR (`MenuId`=17334 AND `OptionIndex`=8) OR (`MenuId`=17334 AND `OptionIndex`=7) OR (`MenuId`=17334 AND `OptionIndex`=6) OR (`MenuId`=17334 AND `OptionIndex`=5) OR (`MenuId`=17334 AND `OptionIndex`=4) OR (`MenuId`=17334 AND `OptionIndex`=3) OR (`MenuId`=17334 AND `OptionIndex`=2) OR (`MenuId`=17334 AND `OptionIndex`=1) OR (`MenuId`=17334 AND `OptionIndex`=0) OR (`MenuId`=17312 AND `OptionIndex`=0) OR (`MenuId`=18324 AND `OptionIndex`=0) OR (`MenuId`=17044 AND `OptionIndex`=0) OR (`MenuId`=17126 AND `OptionIndex`=0) OR (`MenuId`=18275 AND `OptionIndex`=0) OR (`MenuId`=18276 AND `OptionIndex`=0) OR (`MenuId`=17049 AND `OptionIndex`=1) OR (`MenuId`=17128 AND `OptionIndex`=0) OR (`MenuId`=17372 AND `OptionIndex`=4) OR (`MenuId`=17372 AND `OptionIndex`=3) OR (`MenuId`=17372 AND `OptionIndex`=2) OR (`MenuId`=17372 AND `OptionIndex`=1) OR (`MenuId`=17372 AND `OptionIndex`=0) OR (`MenuId`=17349 AND `OptionIndex`=14) OR (`MenuId`=17349 AND `OptionIndex`=13) OR (`MenuId`=17349 AND `OptionIndex`=12) OR (`MenuId`=17349 AND `OptionIndex`=11) OR (`MenuId`=17349 AND `OptionIndex`=10) OR (`MenuId`=17349 AND `OptionIndex`=9) OR (`MenuId`=17349 AND `OptionIndex`=8) OR (`MenuId`=17349 AND `OptionIndex`=7) OR (`MenuId`=17349 AND `OptionIndex`=6) OR (`MenuId`=17349 AND `OptionIndex`=5) OR (`MenuId`=17349 AND `OptionIndex`=4) OR (`MenuId`=17349 AND `OptionIndex`=3) OR (`MenuId`=17349 AND `OptionIndex`=2) OR (`MenuId`=17349 AND `OptionIndex`=1) OR (`MenuId`=17349 AND `OptionIndex`=0) OR (`MenuId`=17348 AND `OptionIndex`=2) OR (`MenuId`=17348 AND `OptionIndex`=1) OR (`MenuId`=17348 AND `OptionIndex`=0) OR (`MenuId`=17344 AND `OptionIndex`=2) OR (`MenuId`=17344 AND `OptionIndex`=1) OR (`MenuId`=17344 AND `OptionIndex`=0) OR (`MenuId`=16597 AND `OptionIndex`=5) OR (`MenuId`=17009 AND `OptionIndex`=1) OR (`MenuId`=17000 AND `OptionIndex`=4) OR (`MenuId`=17000 AND `OptionIndex`=3) OR (`MenuId`=17000 AND `OptionIndex`=2) OR (`MenuId`=17000 AND `OptionIndex`=0) OR (`MenuId`=17271 AND `OptionIndex`=6) OR (`MenuId`=17271 AND `OptionIndex`=3) OR (`MenuId`=17535 AND `OptionIndex`=0) OR (`MenuId`=17308 AND `OptionIndex`=0) OR (`MenuId`=17089 AND `OptionIndex`=1) OR (`MenuId`=17089 AND `OptionIndex`=0) OR (`MenuId`=16292 AND `OptionIndex`=0) OR (`MenuId`=17426 AND `OptionIndex`=0) OR (`MenuId`=16236 AND `OptionIndex`=0) OR (`MenuId`=16872 AND `OptionIndex`=4) OR (`MenuId`=16739 AND `OptionIndex`=0) OR (`MenuId`=16744 AND `OptionIndex`=1) OR (`MenuId`=16744 AND `OptionIndex`=0) OR (`MenuId`=16745 AND `OptionIndex`=1) OR (`MenuId`=16745 AND `OptionIndex`=0) OR (`MenuId`=16743 AND `OptionIndex`=1) OR (`MenuId`=16743 AND `OptionIndex`=0) OR (`MenuId`=16690 AND `OptionIndex`=0) OR (`MenuId`=16526 AND `OptionIndex`=1) OR (`MenuId`=16526 AND `OptionIndex`=0) OR (`MenuId`=16999 AND `OptionIndex`=0) OR (`MenuId`=16986 AND `OptionIndex`=0) OR (`MenuId`=16994 AND `OptionIndex`=0) OR (`MenuId`=17069 AND `OptionIndex`=2) OR (`MenuId`=16862 AND `OptionIndex`=0) OR (`MenuId`=17005 AND `OptionIndex`=0) OR (`MenuId`=16464 AND `OptionIndex`=0) OR (`MenuId`=17199 AND `OptionIndex`=0) OR (`MenuId`=16966 AND `OptionIndex`=0) OR (`MenuId`=16962 AND `OptionIndex`=1) OR (`MenuId`=16561 AND `OptionIndex`=0) OR (`MenuId`=7742 AND `OptionIndex`=1) OR (`MenuId`=7742 AND `OptionIndex`=0) OR (`MenuId`=16609 AND `OptionIndex`=0) OR (`MenuId`=15802 AND `OptionIndex`=0) OR (`MenuId`=17235 AND `OptionIndex`=3) OR (`MenuId`=17235 AND `OptionIndex`=2) OR (`MenuId`=17235 AND `OptionIndex`=1) OR (`MenuId`=17235 AND `OptionIndex`=0) OR (`MenuId`=16598 AND `OptionIndex`=0) OR (`MenuId`=16613 AND `OptionIndex`=0) OR (`MenuId`=16998 AND `OptionIndex`=1) OR (`MenuId`=16871 AND `OptionIndex`=0) OR (`MenuId`=13847 AND `OptionIndex`=6) OR (`MenuId`=13847 AND `OptionIndex`=4) OR (`MenuId`=14314 AND `OptionIndex`=0) OR (`MenuId`=14272 AND `OptionIndex`=0) OR (`MenuId`=14271 AND `OptionIndex`=0) OR (`MenuId`=14655 AND `OptionIndex`=0) OR (`MenuId`=14656 AND `OptionIndex`=0) OR (`MenuId`=13888 AND `OptionIndex`=0) OR (`MenuId`=14398 AND `OptionIndex`=0) OR (`MenuId`=14663 AND `OptionIndex`=0) OR (`MenuId`=14044 AND `OptionIndex`=2) OR (`MenuId`=14275 AND `OptionIndex`=0) OR (`MenuId`=14044 AND `OptionIndex`=1) OR (`MenuId`=14043 AND `OptionIndex`=1) OR (`MenuId`=14046 AND `OptionIndex`=1) OR (`MenuId`=14484 AND `OptionIndex`=0) OR (`MenuId`=13847 AND `OptionIndex`=1) OR (`MenuId`=14667 AND `OptionIndex`=0) OR (`MenuId`=14666 AND `OptionIndex`=0) OR (`MenuId`=14665 AND `OptionIndex`=0) OR (`MenuId`=14664 AND `OptionIndex`=0) OR (`MenuId`=14807 AND `OptionIndex`=1) OR (`MenuId`=14807 AND `OptionIndex`=0) OR (`MenuId`=14641 AND `OptionIndex`=0) OR (`MenuId`=13847 AND `OptionIndex`=0) OR (`MenuId`=15570 AND `OptionIndex`=0) OR (`MenuId`=13781 AND `OptionIndex`=0) OR (`MenuId`=13799 AND `OptionIndex`=0) OR (`MenuId`=13798 AND `OptionIndex`=0) OR (`MenuId`=13797 AND `OptionIndex`=0) OR (`MenuId`=13731 AND `OptionIndex`=0) OR (`MenuId`=13739 AND `OptionIndex`=1) OR (`MenuId`=13739 AND `OptionIndex`=2) OR (`MenuId`=13733 AND `OptionIndex`=0) OR (`MenuId`=14636 AND `OptionIndex`=0) OR (`MenuId`=14599 AND `OptionIndex`=0) OR (`MenuId`=13753 AND `OptionIndex`=0) OR (`MenuId`=13810 AND `OptionIndex`=0) OR (`MenuId`=15041 AND `OptionIndex`=1) OR (`MenuId`=15041 AND `OptionIndex`=0) OR (`MenuId`=14993 AND `OptionIndex`=1) OR (`MenuId`=14993 AND `OptionIndex`=0) OR (`MenuId`=14992 AND `OptionIndex`=1) OR (`MenuId`=14992 AND `OptionIndex`=0) OR (`MenuId`=14986 AND `OptionIndex`=1) OR (`MenuId`=14986 AND `OptionIndex`=0) OR (`MenuId`=14994 AND `OptionIndex`=0) OR (`MenuId`=14867 AND `OptionIndex`=0) OR (`MenuId`=14288 AND `OptionIndex`=0) OR (`MenuId`=14326 AND `OptionIndex`=0) OR (`MenuId`=14304 AND `OptionIndex`=0) OR (`MenuId`=14305 AND `OptionIndex`=0) OR (`MenuId`=14325 AND `OptionIndex`=1) OR (`MenuId`=14325 AND `OptionIndex`=0) OR (`MenuId`=14597 AND `OptionIndex`=0) OR (`MenuId`=13761 AND `OptionIndex`=0) OR (`MenuId`=13760 AND `OptionIndex`=0) OR (`MenuId`=13759 AND `OptionIndex`=0) OR (`MenuId`=13724 AND `OptionIndex`=0) OR (`MenuId`=13723 AND `OptionIndex`=0) OR (`MenuId`=14640 AND `OptionIndex`=0) OR (`MenuId`=13665 AND `OptionIndex`=0) OR (`MenuId`=13690 AND `OptionIndex`=0) OR (`MenuId`=14039 AND `OptionIndex`=1) OR (`MenuId`=14039 AND `OptionIndex`=0) OR (`MenuId`=14648 AND `OptionIndex`=1) OR (`MenuId`=14648 AND `OptionIndex`=0) OR (`MenuId`=13713 AND `OptionIndex`=0) OR (`MenuId`=13714 AND `OptionIndex`=1) OR (`MenuId`=13460 AND `OptionIndex`=0) OR (`MenuId`=13440 AND `OptionIndex`=0) OR (`MenuId`=13494 AND `OptionIndex`=0) OR (`MenuId`=13455 AND `OptionIndex`=1) OR (`MenuId`=13611 AND `OptionIndex`=0) OR (`MenuId`=13537 AND `OptionIndex`=0) OR (`MenuId`=13535 AND `OptionIndex`=0) OR (`MenuId`=13468 AND `OptionIndex`=0) OR (`MenuId`=15091 AND `OptionIndex`=0) OR (`MenuId`=13454 AND `OptionIndex`=0) OR (`MenuId`=13446 AND `OptionIndex`=0) OR (`MenuId`=13455 AND `OptionIndex`=0) OR (`MenuId`=13189 AND `OptionIndex`=0) OR (`MenuId`=13488 AND `OptionIndex`=1) OR (`MenuId`=14916 AND `OptionIndex`=0) OR (`MenuId`=14917 AND `OptionIndex`=0) OR (`MenuId`=14310 AND `OptionIndex`=1) OR (`MenuId`=14310 AND `OptionIndex`=0) OR (`MenuId`=14333 AND `OptionIndex`=0) OR (`MenuId`=13491 AND `OptionIndex`=1) OR (`MenuId`=13499 AND `OptionIndex`=0) OR (`MenuId`=13519 AND `OptionIndex`=0) OR (`MenuId`=13384 AND `OptionIndex`=0) OR (`MenuId`=13419 AND `OptionIndex`=0) OR (`MenuId`=13351 AND `OptionIndex`=2) OR (`MenuId`=13403 AND `OptionIndex`=0) OR (`MenuId`=13387 AND `OptionIndex`=2) OR (`MenuId`=13351 AND `OptionIndex`=0) OR (`MenuId`=13354 AND `OptionIndex`=1) OR (`MenuId`=13354 AND `OptionIndex`=0) OR (`MenuId`=13353 AND `OptionIndex`=1) OR (`MenuId`=13353 AND `OptionIndex`=0) OR (`MenuId`=13355 AND `OptionIndex`=1) OR (`MenuId`=13355 AND `OptionIndex`=0) OR (`MenuId`=14050 AND `OptionIndex`=1) OR (`MenuId`=14050 AND `OptionIndex`=0) OR (`MenuId`=13334 AND `OptionIndex`=0) OR (`MenuId`=13334 AND `OptionIndex`=2) OR (`MenuId`=13850 AND `OptionIndex`=0) OR (`MenuId`=13850 AND `OptionIndex`=2) OR (`MenuId`=13332 AND `OptionIndex`=0) OR (`MenuId`=13593 AND `OptionIndex`=0) OR (`MenuId`=13338 AND `OptionIndex`=0) OR (`MenuId`=13853 AND `OptionIndex`=1) OR (`MenuId`=13594 AND `OptionIndex`=0) OR (`MenuId`=13409 AND `OptionIndex`=1) OR (`MenuId`=13445 AND `OptionIndex`=2) OR (`MenuId`=13653 AND `OptionIndex`=11) OR (`MenuId`=13653 AND `OptionIndex`=10) OR (`MenuId`=13653 AND `OptionIndex`=9) OR (`MenuId`=13653 AND `OptionIndex`=8) OR (`MenuId`=13653 AND `OptionIndex`=7) OR (`MenuId`=13653 AND `OptionIndex`=6) OR (`MenuId`=13653 AND `OptionIndex`=5) OR (`MenuId`=13653 AND `OptionIndex`=4) OR (`MenuId`=13653 AND `OptionIndex`=3) OR (`MenuId`=13653 AND `OptionIndex`=2) OR (`MenuId`=13653 AND `OptionIndex`=1) OR (`MenuId`=13653 AND `OptionIndex`=0) OR (`MenuId`=15156 AND `OptionIndex`=0) OR (`MenuId`=13663 AND `OptionIndex`=0) OR (`MenuId`=13662 AND `OptionIndex`=0) OR (`MenuId`=13661 AND `OptionIndex`=0) OR (`MenuId`=13660 AND `OptionIndex`=0) OR (`MenuId`=13659 AND `OptionIndex`=0) OR (`MenuId`=13658 AND `OptionIndex`=0) OR (`MenuId`=13657 AND `OptionIndex`=0) OR (`MenuId`=13656 AND `OptionIndex`=0) OR (`MenuId`=13655 AND `OptionIndex`=0) OR (`MenuId`=13654 AND `OptionIndex`=0) OR (`MenuId`=13642 AND `OptionIndex`=1) OR (`MenuId`=13476 AND `OptionIndex`=10) OR (`MenuId`=13476 AND `OptionIndex`=9) OR (`MenuId`=13476 AND `OptionIndex`=8) OR (`MenuId`=13476 AND `OptionIndex`=7) OR (`MenuId`=13476 AND `OptionIndex`=6) OR (`MenuId`=13476 AND `OptionIndex`=5) OR (`MenuId`=13476 AND `OptionIndex`=4) OR (`MenuId`=13476 AND `OptionIndex`=3) OR (`MenuId`=13476 AND `OptionIndex`=2) OR (`MenuId`=13476 AND `OptionIndex`=1) OR (`MenuId`=13476 AND `OptionIndex`=0) OR (`MenuId`=13445 AND `OptionIndex`=1) OR (`MenuId`=13641 AND `OptionIndex`=0) OR (`MenuId`=13642 AND `OptionIndex`=0) OR (`MenuId`=13584 AND `OptionIndex`=2) OR (`MenuId`=13583 AND `OptionIndex`=2) OR (`MenuId`=14379 AND `OptionIndex`=1) OR (`MenuId`=14379 AND `OptionIndex`=0) OR (`MenuId`=14585 AND `OptionIndex`=0) OR (`MenuId`=14422 AND `OptionIndex`=0) OR (`MenuId`=13608 AND `OptionIndex`=2) OR (`MenuId`=14581 AND `OptionIndex`=0) OR (`MenuId`=13609 AND `OptionIndex`=2) OR (`MenuId`=14584 AND `OptionIndex`=0) OR (`MenuId`=14583 AND `OptionIndex`=0) OR (`MenuId`=15579 AND `OptionIndex`=20) OR (`MenuId`=15579 AND `OptionIndex`=18) OR (`MenuId`=15579 AND `OptionIndex`=11) OR (`MenuId`=15579 AND `OptionIndex`=10) OR (`MenuId`=13343 AND `OptionIndex`=0) OR (`MenuId`=13315 AND `OptionIndex`=0) OR (`MenuId`=13740 AND `OptionIndex`=0) OR (`MenuId`=13279 AND `OptionIndex`=0) OR (`MenuId`=13750 AND `OptionIndex`=0) OR (`MenuId`=13742 AND `OptionIndex`=0) OR (`MenuId`=13741 AND `OptionIndex`=0) OR (`MenuId`=13270 AND `OptionIndex`=0) OR (`MenuId`=14315 AND `OptionIndex`=1) OR (`MenuId`=14315 AND `OptionIndex`=0) OR (`MenuId`=14330 AND `OptionIndex`=1) OR (`MenuId`=14330 AND `OptionIndex`=0) OR (`MenuId`=14934 AND `OptionIndex`=0) OR (`MenuId`=13230 AND `OptionIndex`=11) OR (`MenuId`=13230 AND `OptionIndex`=10) OR (`MenuId`=13230 AND `OptionIndex`=9) OR (`MenuId`=13230 AND `OptionIndex`=5) OR (`MenuId`=13230 AND `OptionIndex`=4) OR (`MenuId`=13230 AND `OptionIndex`=3) OR (`MenuId`=13230 AND `OptionIndex`=2) OR (`MenuId`=13230 AND `OptionIndex`=1) OR (`MenuId`=13230 AND `OptionIndex`=0) OR (`MenuId`=13230 AND `OptionIndex`=8) OR (`MenuId`=13230 AND `OptionIndex`=7) OR (`MenuId`=13230 AND `OptionIndex`=6) OR (`MenuId`=13237 AND `OptionIndex`=0) OR (`MenuId`=12009 AND `OptionIndex`=0) OR (`MenuId`=11689 AND `OptionIndex`=1) OR (`MenuId`=12243 AND `OptionIndex`=6) OR (`MenuId`=12243 AND `OptionIndex`=5) OR (`MenuId`=12243 AND `OptionIndex`=4) OR (`MenuId`=12243 AND `OptionIndex`=3) OR (`MenuId`=12243 AND `OptionIndex`=2) OR (`MenuId`=19861 AND `OptionIndex`=0) OR (`MenuId`=20486 AND `OptionIndex`=0) OR (`MenuId`=19930 AND `OptionIndex`=1) OR (`MenuId`=19930 AND `OptionIndex`=0) OR (`MenuId`=18488 AND `OptionIndex`=1) OR (`MenuId`=18486 AND `OptionIndex`=7) OR (`MenuId`=18486 AND `OptionIndex`=6) OR (`MenuId`=18337 AND `OptionIndex`=2) OR (`MenuId`=18337 AND `OptionIndex`=1) OR (`MenuId`=18337 AND `OptionIndex`=0) OR (`MenuId`=18226 AND `OptionIndex`=0) OR (`MenuId`=18328 AND `OptionIndex`=0) OR (`MenuId`=18253 AND `OptionIndex`=2) OR (`MenuId`=18582 AND `OptionIndex`=4) OR (`MenuId`=18582 AND `OptionIndex`=2) OR (`MenuId`=18582 AND `OptionIndex`=0) OR (`MenuId`=16242 AND `OptionIndex`=0) OR (`MenuId`=16663 AND `OptionIndex`=2) OR (`MenuId`=16663 AND `OptionIndex`=1) OR (`MenuId`=16663 AND `OptionIndex`=0) OR (`MenuId`=17533 AND `OptionIndex`=0) OR (`MenuId`=16940 AND `OptionIndex`=1) OR (`MenuId`=16424 AND `OptionIndex`=0) OR (`MenuId`=15997 AND `OptionIndex`=0) OR (`MenuId`=16442 AND `OptionIndex`=2) OR (`MenuId`=16442 AND `OptionIndex`=1) OR (`MenuId`=16442 AND `OptionIndex`=0) OR (`MenuId`=15997 AND `OptionIndex`=3) OR (`MenuId`=15997 AND `OptionIndex`=2) OR (`MenuId`=15997 AND `OptionIndex`=1) OR (`MenuId`=16395 AND `OptionIndex`=8) OR (`MenuId`=16395 AND `OptionIndex`=3) OR (`MenuId`=16395 AND `OptionIndex`=0) OR (`MenuId`=16396 AND `OptionIndex`=2) OR (`MenuId`=16396 AND `OptionIndex`=1) OR (`MenuId`=16396 AND `OptionIndex`=0) OR (`MenuId`=15860 AND `OptionIndex`=0) OR (`MenuId`=16454 AND `OptionIndex`=1) OR (`MenuId`=16454 AND `OptionIndex`=0) OR (`MenuId`=15174 AND `OptionIndex`=3) OR (`MenuId`=15212 AND `OptionIndex`=0) OR (`MenuId`=14955 AND `OptionIndex`=1) OR (`MenuId`=16509 AND `OptionIndex`=13) OR (`MenuId`=16509 AND `OptionIndex`=12) OR (`MenuId`=16509 AND `OptionIndex`=11) OR (`MenuId`=16509 AND `OptionIndex`=10) OR (`MenuId`=16509 AND `OptionIndex`=9) OR (`MenuId`=16509 AND `OptionIndex`=8) OR (`MenuId`=16509 AND `OptionIndex`=7) OR (`MenuId`=16509 AND `OptionIndex`=6) OR (`MenuId`=16509 AND `OptionIndex`=5) OR (`MenuId`=16509 AND `OptionIndex`=4) OR (`MenuId`=16509 AND `OptionIndex`=3) OR (`MenuId`=16509 AND `OptionIndex`=2) OR (`MenuId`=16509 AND `OptionIndex`=1) OR (`MenuId`=16370 AND `OptionIndex`=6) OR (`MenuId`=16370 AND `OptionIndex`=5) OR (`MenuId`=16370 AND `OptionIndex`=4) OR (`MenuId`=16370 AND `OptionIndex`=3) OR (`MenuId`=16370 AND `OptionIndex`=2) OR (`MenuId`=16370 AND `OptionIndex`=1) OR (`MenuId`=16364 AND `OptionIndex`=16) OR (`MenuId`=16364 AND `OptionIndex`=15) OR (`MenuId`=16364 AND `OptionIndex`=14) OR (`MenuId`=16364 AND `OptionIndex`=13) OR (`MenuId`=16364 AND `OptionIndex`=12) OR (`MenuId`=16364 AND `OptionIndex`=10) OR (`MenuId`=16364 AND `OptionIndex`=9) OR (`MenuId`=16364 AND `OptionIndex`=8) OR (`MenuId`=16364 AND `OptionIndex`=7) OR (`MenuId`=16364 AND `OptionIndex`=6) OR (`MenuId`=16364 AND `OptionIndex`=5) OR (`MenuId`=16364 AND `OptionIndex`=4) OR (`MenuId`=16364 AND `OptionIndex`=3) OR (`MenuId`=16364 AND `OptionIndex`=2) OR (`MenuId`=16364 AND `OptionIndex`=1) OR (`MenuId`=14615 AND `OptionIndex`=1) OR (`MenuId`=14615 AND `OptionIndex`=0) OR (`MenuId`=14582 AND `OptionIndex`=0) OR (`MenuId`=15152 AND `OptionIndex`=11) OR (`MenuId`=15152 AND `OptionIndex`=10) OR (`MenuId`=15152 AND `OptionIndex`=9) OR (`MenuId`=15152 AND `OptionIndex`=8) OR (`MenuId`=15152 AND `OptionIndex`=7) OR (`MenuId`=15152 AND `OptionIndex`=6) OR (`MenuId`=15152 AND `OptionIndex`=5) OR (`MenuId`=15152 AND `OptionIndex`=4) OR (`MenuId`=15152 AND `OptionIndex`=3) OR (`MenuId`=15152 AND `OptionIndex`=2) OR (`MenuId`=15152 AND `OptionIndex`=1) OR (`MenuId`=14404 AND `OptionIndex`=0) OR (`MenuId`=14558 AND `OptionIndex`=11) OR (`MenuId`=14558 AND `OptionIndex`=10) OR (`MenuId`=14558 AND `OptionIndex`=9) OR (`MenuId`=14558 AND `OptionIndex`=7) OR (`MenuId`=14558 AND `OptionIndex`=6) OR (`MenuId`=14558 AND `OptionIndex`=5) OR (`MenuId`=14558 AND `OptionIndex`=4) OR (`MenuId`=14558 AND `OptionIndex`=3) OR (`MenuId`=14558 AND `OptionIndex`=2) OR (`MenuId`=14558 AND `OptionIndex`=1) OR (`MenuId`=15718 AND `OptionIndex`=0) OR (`MenuId`=15952 AND `OptionIndex`=0) OR (`MenuId`=14680 AND `OptionIndex`=2) OR (`MenuId`=14680 AND `OptionIndex`=0) OR (`MenuId`=14806 AND `OptionIndex`=0) OR (`MenuId`=14833 AND `OptionIndex`=11) OR (`MenuId`=14833 AND `OptionIndex`=10) OR (`MenuId`=14833 AND `OptionIndex`=9) OR (`MenuId`=14833 AND `OptionIndex`=7) OR (`MenuId`=14833 AND `OptionIndex`=6) OR (`MenuId`=14833 AND `OptionIndex`=5) OR (`MenuId`=14833 AND `OptionIndex`=4) OR (`MenuId`=14833 AND `OptionIndex`=3) OR (`MenuId`=14833 AND `OptionIndex`=2) OR (`MenuId`=14833 AND `OptionIndex`=1) OR (`MenuId`=14690 AND `OptionIndex`=0) OR (`MenuId`=15690 AND `OptionIndex`=0) OR (`MenuId`=15107 AND `OptionIndex`=0) OR (`MenuId`=14518 AND `OptionIndex`=0) OR (`MenuId`=14346 AND `OptionIndex`=1) OR (`MenuId`=14346 AND `OptionIndex`=0) OR (`MenuId`=14523 AND `OptionIndex`=0) OR (`MenuId`=14522 AND `OptionIndex`=1) OR (`MenuId`=14522 AND `OptionIndex`=0) OR (`MenuId`=13651 AND `OptionIndex`=2) OR (`MenuId`=14514 AND `OptionIndex`=0) OR (`MenuId`=14347 AND `OptionIndex`=1) OR (`MenuId`=14347 AND `OptionIndex`=0) OR (`MenuId`=14348 AND `OptionIndex`=3) OR (`MenuId`=14348 AND `OptionIndex`=2) OR (`MenuId`=14348 AND `OptionIndex`=1) OR (`MenuId`=14512 AND `OptionIndex`=0) OR (`MenuId`=14513 AND `OptionIndex`=0) OR (`MenuId`=14510 AND `OptionIndex`=0) OR (`MenuId`=14508 AND `OptionIndex`=0) OR (`MenuId`=14507 AND `OptionIndex`=1) OR (`MenuId`=14507 AND `OptionIndex`=0) OR (`MenuId`=14504 AND `OptionIndex`=0) OR (`MenuId`=14505 AND `OptionIndex`=0) OR (`MenuId`=14350 AND `OptionIndex`=1) OR (`MenuId`=14350 AND `OptionIndex`=0) OR (`MenuId`=14503 AND `OptionIndex`=0) OR (`MenuId`=14349 AND `OptionIndex`=1) OR (`MenuId`=14349 AND `OptionIndex`=0) OR (`MenuId`=14351 AND `OptionIndex`=1) OR (`MenuId`=14351 AND `OptionIndex`=0) OR (`MenuId`=14520 AND `OptionIndex`=0) OR (`MenuId`=14519 AND `OptionIndex`=1) OR (`MenuId`=14519 AND `OptionIndex`=0) OR (`MenuId`=14575 AND `OptionIndex`=0) OR (`MenuId`=14692 AND `OptionIndex`=2) OR (`MenuId`=14692 AND `OptionIndex`=1) OR (`MenuId`=14692 AND `OptionIndex`=0) OR (`MenuId`=14751 AND `OptionIndex`=0) OR (`MenuId`=14752 AND `OptionIndex`=0) OR (`MenuId`=14693 AND `OptionIndex`=22) OR (`MenuId`=14693 AND `OptionIndex`=21) OR (`MenuId`=14693 AND `OptionIndex`=20) OR (`MenuId`=14693 AND `OptionIndex`=19) OR (`MenuId`=14693 AND `OptionIndex`=18) OR (`MenuId`=14693 AND `OptionIndex`=17) OR (`MenuId`=14693 AND `OptionIndex`=16) OR (`MenuId`=14693 AND `OptionIndex`=15) OR (`MenuId`=14693 AND `OptionIndex`=14) OR (`MenuId`=14693 AND `OptionIndex`=13) OR (`MenuId`=14693 AND `OptionIndex`=12) OR (`MenuId`=14693 AND `OptionIndex`=11) OR (`MenuId`=14693 AND `OptionIndex`=10) OR (`MenuId`=14693 AND `OptionIndex`=9) OR (`MenuId`=14693 AND `OptionIndex`=8) OR (`MenuId`=14693 AND `OptionIndex`=7) OR (`MenuId`=14693 AND `OptionIndex`=6) OR (`MenuId`=14693 AND `OptionIndex`=5) OR (`MenuId`=14693 AND `OptionIndex`=4) OR (`MenuId`=14693 AND `OptionIndex`=3) OR (`MenuId`=14693 AND `OptionIndex`=2) OR (`MenuId`=14693 AND `OptionIndex`=1) OR (`MenuId`=14693 AND `OptionIndex`=0) OR (`MenuId`=14771 AND `OptionIndex`=0) OR (`MenuId`=14750 AND `OptionIndex`=0) OR (`MenuId`=14749 AND `OptionIndex`=0) OR (`MenuId`=14748 AND `OptionIndex`=0) OR (`MenuId`=14747 AND `OptionIndex`=0) OR (`MenuId`=14746 AND `OptionIndex`=0) OR (`MenuId`=14745 AND `OptionIndex`=0) OR (`MenuId`=14744 AND `OptionIndex`=0) OR (`MenuId`=14743 AND `OptionIndex`=0) OR (`MenuId`=14742 AND `OptionIndex`=0) OR (`MenuId`=14770 AND `OptionIndex`=0) OR (`MenuId`=14741 AND `OptionIndex`=0) OR (`MenuId`=14740 AND `OptionIndex`=0) OR (`MenuId`=14739 AND `OptionIndex`=0) OR (`MenuId`=14738 AND `OptionIndex`=0) OR (`MenuId`=14737 AND `OptionIndex`=0) OR (`MenuId`=14736 AND `OptionIndex`=0) OR (`MenuId`=14735 AND `OptionIndex`=0) OR (`MenuId`=14697 AND `OptionIndex`=0) OR (`MenuId`=14696 AND `OptionIndex`=0) OR (`MenuId`=14695 AND `OptionIndex`=0) OR (`MenuId`=14694 AND `OptionIndex`=0) OR (`MenuId`=14691 AND `OptionIndex`=0) OR (`MenuId`=14772 AND `OptionIndex`=13) OR (`MenuId`=14772 AND `OptionIndex`=12) OR (`MenuId`=14772 AND `OptionIndex`=11) OR (`MenuId`=14772 AND `OptionIndex`=10) OR (`MenuId`=14772 AND `OptionIndex`=9) OR (`MenuId`=14772 AND `OptionIndex`=8) OR (`MenuId`=14772 AND `OptionIndex`=7) OR (`MenuId`=14772 AND `OptionIndex`=5) OR (`MenuId`=14772 AND `OptionIndex`=4) OR (`MenuId`=14772 AND `OptionIndex`=3) OR (`MenuId`=14772 AND `OptionIndex`=2) OR (`MenuId`=14772 AND `OptionIndex`=1) OR (`MenuId`=14772 AND `OptionIndex`=0) OR (`MenuId`=14785 AND `OptionIndex`=0) OR (`MenuId`=14784 AND `OptionIndex`=0) OR (`MenuId`=14783 AND `OptionIndex`=0) OR (`MenuId`=14782 AND `OptionIndex`=0) OR (`MenuId`=14781 AND `OptionIndex`=0) OR (`MenuId`=14780 AND `OptionIndex`=0) OR (`MenuId`=14778 AND `OptionIndex`=0) OR (`MenuId`=14776 AND `OptionIndex`=0) OR (`MenuId`=14775 AND `OptionIndex`=0) OR (`MenuId`=14831 AND `OptionIndex`=0) OR (`MenuId`=14774 AND `OptionIndex`=0) OR (`MenuId`=14773 AND `OptionIndex`=0) OR (`MenuId`=14769 AND `OptionIndex`=15) OR (`MenuId`=14769 AND `OptionIndex`=14) OR (`MenuId`=14769 AND `OptionIndex`=13) OR (`MenuId`=14769 AND `OptionIndex`=12) OR (`MenuId`=14769 AND `OptionIndex`=11) OR (`MenuId`=14769 AND `OptionIndex`=10) OR (`MenuId`=14769 AND `OptionIndex`=9) OR (`MenuId`=14769 AND `OptionIndex`=8) OR (`MenuId`=14769 AND `OptionIndex`=7) OR (`MenuId`=14769 AND `OptionIndex`=6) OR (`MenuId`=14769 AND `OptionIndex`=5) OR (`MenuId`=14769 AND `OptionIndex`=4) OR (`MenuId`=14769 AND `OptionIndex`=3) OR (`MenuId`=14769 AND `OptionIndex`=2) OR (`MenuId`=14769 AND `OptionIndex`=1) OR (`MenuId`=14769 AND `OptionIndex`=0) OR (`MenuId`=14768 AND `OptionIndex`=0) OR (`MenuId`=14767 AND `OptionIndex`=0) OR (`MenuId`=14766 AND `OptionIndex`=0) OR (`MenuId`=14765 AND `OptionIndex`=0) OR (`MenuId`=14764 AND `OptionIndex`=0) OR (`MenuId`=14763 AND `OptionIndex`=0) OR (`MenuId`=14761 AND `OptionIndex`=0) OR (`MenuId`=14762 AND `OptionIndex`=0) OR (`MenuId`=14754 AND `OptionIndex`=0) OR (`MenuId`=14760 AND `OptionIndex`=0) OR (`MenuId`=14759 AND `OptionIndex`=0) OR (`MenuId`=14758 AND `OptionIndex`=0) OR (`MenuId`=14756 AND `OptionIndex`=0) OR (`MenuId`=14757 AND `OptionIndex`=0) OR (`MenuId`=14755 AND `OptionIndex`=0) OR (`MenuId`=14689 AND `OptionIndex`=0) OR (`MenuId`=14688 AND `OptionIndex`=0) OR (`MenuId`=14686 AND `OptionIndex`=0) OR (`MenuId`=14561 AND `OptionIndex`=0) OR (`MenuId`=15127 AND `OptionIndex`=2) OR (`MenuId`=14630 AND `OptionIndex`=0) OR (`MenuId`=14470 AND `OptionIndex`=0) OR (`MenuId`=13637 AND `OptionIndex`=0) OR (`MenuId`=13635 AND `OptionIndex`=1) OR (`MenuId`=13635 AND `OptionIndex`=0) OR (`MenuId`=13691 AND `OptionIndex`=0) OR (`MenuId`=13692 AND `OptionIndex`=0) OR (`MenuId`=13636 AND `OptionIndex`=0) OR (`MenuId`=13644 AND `OptionIndex`=0) OR (`MenuId`=13591 AND `OptionIndex`=0) OR (`MenuId`=13554 AND `OptionIndex`=0) OR (`MenuId`=13671 AND `OptionIndex`=1) OR (`MenuId`=13671 AND `OptionIndex`=0) OR (`MenuId`=13852 AND `OptionIndex`=0) OR (`MenuId`=13851 AND `OptionIndex`=0) OR (`MenuId`=15540 AND `OptionIndex`=0) OR (`MenuId`=14528 AND `OptionIndex`=0) OR (`MenuId`=13789 AND `OptionIndex`=0) OR (`MenuId`=14868 AND `OptionIndex`=0) OR (`MenuId`=14855 AND `OptionIndex`=0) OR (`MenuId`=13783 AND `OptionIndex`=0) OR (`MenuId`=13803 AND `OptionIndex`=0) OR (`MenuId`=14800 AND `OptionIndex`=0) OR (`MenuId`=14530 AND `OptionIndex`=0) OR (`MenuId`=14532 AND `OptionIndex`=0) OR (`MenuId`=13580 AND `OptionIndex`=1) OR (`MenuId`=13580 AND `OptionIndex`=0) OR (`MenuId`=13044 AND `OptionIndex`=0) OR (`MenuId`=13646 AND `OptionIndex`=0) OR (`MenuId`=14381 AND `OptionIndex`=0) OR (`MenuId`=14364 AND `OptionIndex`=0) OR (`MenuId`=13592 AND `OptionIndex`=0) OR (`MenuId`=13605 AND `OptionIndex`=1) OR (`MenuId`=13605 AND `OptionIndex`=0) OR (`MenuId`=13581 AND `OptionIndex`=0) OR (`MenuId`=13228 AND `OptionIndex`=0) OR (`MenuId`=13281 AND `OptionIndex`=0) OR (`MenuId`=13325 AND `OptionIndex`=0) OR (`MenuId`=13324 AND `OptionIndex`=1) OR (`MenuId`=13372 AND `OptionIndex`=0) OR (`MenuId`=13371 AND `OptionIndex`=0) OR (`MenuId`=13550 AND `OptionIndex`=2) OR (`MenuId`=13550 AND `OptionIndex`=0) OR (`MenuId`=13551 AND `OptionIndex`=0) OR (`MenuId`=13550 AND `OptionIndex`=1) OR (`MenuId`=13553 AND `OptionIndex`=0) OR (`MenuId`=13549 AND `OptionIndex`=0) OR (`MenuId`=14941 AND `OptionIndex`=0) OR (`MenuId`=13396 AND `OptionIndex`=1) OR (`MenuId`=13401 AND `OptionIndex`=2) OR (`MenuId`=13401 AND `OptionIndex`=1) OR (`MenuId`=13401 AND `OptionIndex`=0) OR (`MenuId`=13058 AND `OptionIndex`=0) OR (`MenuId`=13054 AND `OptionIndex`=0) OR (`MenuId`=13057 AND `OptionIndex`=0) OR (`MenuId`=13059 AND `OptionIndex`=0) OR (`MenuId`=13072 AND `OptionIndex`=1) OR (`MenuId`=13072 AND `OptionIndex`=0) OR (`MenuId`=13070 AND `OptionIndex`=2) OR (`MenuId`=13070 AND `OptionIndex`=0) OR (`MenuId`=13105 AND `OptionIndex`=0) OR (`MenuId`=14624 AND `OptionIndex`=0) OR (`MenuId`=14649 AND `OptionIndex`=8) OR (`MenuId`=14626 AND `OptionIndex`=1) OR (`MenuId`=14626 AND `OptionIndex`=0) OR (`MenuId`=14625 AND `OptionIndex`=0) OR (`MenuId`=13226 AND `OptionIndex`=0) OR (`MenuId`=13225 AND `OptionIndex`=0) OR (`MenuId`=13227 AND `OptionIndex`=0) OR (`MenuId`=13291 AND `OptionIndex`=0) OR (`MenuId`=13808 AND `OptionIndex`=0) OR (`MenuId`=13427 AND `OptionIndex`=5) OR (`MenuId`=13286 AND `OptionIndex`=1) OR (`MenuId`=13286 AND `OptionIndex`=0) OR (`MenuId`=13530 AND `OptionIndex`=1) OR (`MenuId`=13137 AND `OptionIndex`=0) OR (`MenuId`=13110 AND `OptionIndex`=0) OR (`MenuId`=13109 AND `OptionIndex`=0) OR (`MenuId`=13552 AND `OptionIndex`=0) OR (`MenuId`=13374 AND `OptionIndex`=2) OR (`MenuId`=13374 AND `OptionIndex`=1) OR (`MenuId`=13283 AND `OptionIndex`=1) OR (`MenuId`=13283 AND `OptionIndex`=0) OR (`MenuId`=13782 AND `OptionIndex`=0) OR (`MenuId`=14628 AND `OptionIndex`=1) OR (`MenuId`=14628 AND `OptionIndex`=0) OR (`MenuId`=13538 AND `OptionIndex`=1) OR (`MenuId`=13538 AND `OptionIndex`=0) OR (`MenuId`=13254 AND `OptionIndex`=0) OR (`MenuId`=13531 AND `OptionIndex`=3) OR (`MenuId`=13531 AND `OptionIndex`=2) OR (`MenuId`=13531 AND `OptionIndex`=1) OR (`MenuId`=13531 AND `OptionIndex`=0) OR (`MenuId`=14280 AND `OptionIndex`=3) OR (`MenuId`=14280 AND `OptionIndex`=2) OR (`MenuId`=14280 AND `OptionIndex`=0) OR (`MenuId`=13272 AND `OptionIndex`=3) OR (`MenuId`=13272 AND `OptionIndex`=2) OR (`MenuId`=13272 AND `OptionIndex`=1) OR (`MenuId`=13272 AND `OptionIndex`=0) OR (`MenuId`=13274 AND `OptionIndex`=3) OR (`MenuId`=13274 AND `OptionIndex`=2) OR (`MenuId`=13274 AND `OptionIndex`=1) OR (`MenuId`=13274 AND `OptionIndex`=0) OR (`MenuId`=13273 AND `OptionIndex`=3) OR (`MenuId`=13273 AND `OptionIndex`=2) OR (`MenuId`=13273 AND `OptionIndex`=1) OR (`MenuId`=13273 AND `OptionIndex`=0) OR (`MenuId`=13271 AND `OptionIndex`=3) OR (`MenuId`=13271 AND `OptionIndex`=2) OR (`MenuId`=13271 AND `OptionIndex`=1) OR (`MenuId`=13271 AND `OptionIndex`=0) OR (`MenuId`=13265 AND `OptionIndex`=0) OR (`MenuId`=13128 AND `OptionIndex`=0) OR (`MenuId`=13115 AND `OptionIndex`=0) OR (`MenuId`=13250 AND `OptionIndex`=0) OR (`MenuId`=13281 AND `OptionIndex`=1) OR (`MenuId`=13510 AND `OptionIndex`=0) OR (`MenuId`=13250 AND `OptionIndex`=1) OR (`MenuId`=13509 AND `OptionIndex`=0) OR (`MenuId`=13809 AND `OptionIndex`=0) OR (`MenuId`=13312 AND `OptionIndex`=1) OR (`MenuId`=14918 AND `OptionIndex`=0) OR (`MenuId`=14912 AND `OptionIndex`=0) OR (`MenuId`=14913 AND `OptionIndex`=0) OR (`MenuId`=15110 AND `OptionIndex`=0) OR (`MenuId`=14935 AND `OptionIndex`=1) OR (`MenuId`=14935 AND `OptionIndex`=0) OR (`MenuId`=15099 AND `OptionIndex`=0) OR (`MenuId`=15100 AND `OptionIndex`=0) OR (`MenuId`=14926 AND `OptionIndex`=0) OR (`MenuId`=15098 AND `OptionIndex`=0) OR (`MenuId`=14971 AND `OptionIndex`=1) OR (`MenuId`=14971 AND `OptionIndex`=0) OR (`MenuId`=15111 AND `OptionIndex`=0) OR (`MenuId`=11920 AND `OptionIndex`=0) OR (`MenuId`=12591 AND `OptionIndex`=0) OR (`MenuId`=11535 AND `OptionIndex`=0) OR (`MenuId`=11574 AND `OptionIndex`=0) OR (`MenuId`=11581 AND `OptionIndex`=0) OR (`MenuId`=11580 AND `OptionIndex`=0) OR (`MenuId`=11579 AND `OptionIndex`=0) OR (`MenuId`=11578 AND `OptionIndex`=0) OR (`MenuId`=11577 AND `OptionIndex`=0) OR (`MenuId`=11576 AND `OptionIndex`=0) OR (`MenuId`=11575 AND `OptionIndex`=0) OR (`MenuId`=11535 AND `OptionIndex`=7) OR (`MenuId`=11592 AND `OptionIndex`=0) OR (`MenuId`=11535 AND `OptionIndex`=1) OR (`MenuId`=11535 AND `OptionIndex`=5) OR (`MenuId`=11535 AND `OptionIndex`=3) OR (`MenuId`=11535 AND `OptionIndex`=2) OR (`MenuId`=11477 AND `OptionIndex`=0) OR (`MenuId`=11525 AND `OptionIndex`=1) OR (`MenuId`=11525 AND `OptionIndex`=0) OR (`MenuId`=11352 AND `OptionIndex`=5) OR (`MenuId`=11352 AND `OptionIndex`=4) OR (`MenuId`=11352 AND `OptionIndex`=3) OR (`MenuId`=11352 AND `OptionIndex`=2) OR (`MenuId`=11352 AND `OptionIndex`=1) OR (`MenuId`=11608 AND `OptionIndex`=0) OR (`MenuId`=17546 AND `OptionIndex`=0) OR (`MenuId`=17557 AND `OptionIndex`=0) OR (`MenuId`=17104 AND `OptionIndex`=0) OR (`MenuId`=16707 AND `OptionIndex`=1) OR (`MenuId`=16665 AND `OptionIndex`=0) OR (`MenuId`=16664 AND `OptionIndex`=0) OR (`MenuId`=16662 AND `OptionIndex`=0) OR (`MenuId`=16793 AND `OptionIndex`=0) OR (`MenuId`=16792 AND `OptionIndex`=0) OR (`MenuId`=16329 AND `OptionIndex`=0) OR (`MenuId`=18867 AND `OptionIndex`=1) OR (`MenuId`=16777 AND `OptionIndex`=1) OR (`MenuId`=17203 AND `OptionIndex`=0) OR (`MenuId`=16686 AND `OptionIndex`=0) OR (`MenuId`=16895 AND `OptionIndex`=0) OR (`MenuId`=16542 AND `OptionIndex`=0) OR (`MenuId`=16538 AND `OptionIndex`=0) OR (`MenuId`=16539 AND `OptionIndex`=0) OR (`MenuId`=18491 AND `OptionIndex`=0) OR (`MenuId`=18486 AND `OptionIndex`=5) OR (`MenuId`=18189 AND `OptionIndex`=0) OR (`MenuId`=16762 AND `OptionIndex`=2) OR (`MenuId`=16849 AND `OptionIndex`=1) OR (`MenuId`=16849 AND `OptionIndex`=0) OR (`MenuId`=16703 AND `OptionIndex`=0) OR (`MenuId`=16515 AND `OptionIndex`=0) OR (`MenuId`=17246 AND `OptionIndex`=0) OR (`MenuId`=16822 AND `OptionIndex`=0) OR (`MenuId`=16737 AND `OptionIndex`=3) OR (`MenuId`=16737 AND `OptionIndex`=1) OR (`MenuId`=16737 AND `OptionIndex`=0) OR (`MenuId`=16651 AND `OptionIndex`=0) OR (`MenuId`=16502 AND `OptionIndex`=0) OR (`MenuId`=16876 AND `OptionIndex`=1) OR (`MenuId`=16977 AND `OptionIndex`=0) OR (`MenuId`=17275 AND `OptionIndex`=0) OR (`MenuId`=16854 AND `OptionIndex`=0) OR (`MenuId`=16817 AND `OptionIndex`=0) OR (`MenuId`=16762 AND `OptionIndex`=0) OR (`MenuId`=16652 AND `OptionIndex`=0);
INSERT INTO `gossip_menu_option` (`MenuId`, `OptionIndex`, `OptionIcon`, `OptionText`, `OptionBroadcastTextId`, `VerifiedBuild`) VALUES
(18491, 1, 0, 'Take me to the Tanaan Jungle.', 96072, 27602),
(18326, 1, 0, 'Take me to the Tanaan Jungle.', 96072, 27602),
(18488, 0, 1, 'What kind of naval equipment do you have?', 95559, 27602),
(17051, 0, 1, 'I would like to buy from you.', 14967, 27602), -- OptionBroadcastTextID: 2583 - 6399 - 7142 - 9992 - 14967
(16872, 0, 28, 'I\'d like to submit a work order.', 85816, 27602),
(16707, 2, 2, 'Show me where I can fly.', 12271, 27602),
(16877, 1, 2, 'Show me where I can fly.', 12271, 27602),
(16718, 1, 3, 'Train me in Inscription.', 88801, 27602), -- OptionBroadcastTextID: 47113 - 88801
(16718, 0, 3, 'Train me in Archaeology.', 88800, 27602), -- OptionBroadcastTextID: 88647 - 88800
(16283, 0, 2, 'Show me where I can fly.', 12271, 27602),
(16597, 0, 2, 'Show me where I can fly.', 12271, 27602),
(16897, 0, 30, 'I\'m looking to recruit someone.', 86488, 27602),
(17055, 0, 1, 'I want a new recipe for myself.', 85295, 27602),
(17431, 0, 28, 'I would like to place a work order.', 83605, 27602),
(16864, 0, 1, 'I want a new recipe for myself.', 85295, 27602),
(18201, 30, 0, 'Play \"Way of the Monk\"', 92960, 27602),
(18201, 15, 0, 'Play Default Garrison Music', 93061, 27602),
(18201, 14, 0, 'Play \"Curse of the Worgen\"', 92959, 27602),
(18201, 13, 0, 'Play \"Exodar\"', 92958, 27602),
(18201, 12, 0, 'Play \"Tinkertown\"', 92957, 27602),
(18201, 11, 0, 'Play \"Gnomeregan\"', 92956, 27602),
(18201, 10, 0, 'Play \"Night Song\"', 92954, 27602),
(18201, 8, 0, 'Play \"Ironforge\"', 92952, 27602),
(18201, 6, 0, 'Play \"Stormwind\"', 86740, 27602),
(18268, 1, 0, 'Where can I get more music rolls?', 93689, 27602),
(18268, 0, 0, 'Where are the jukebox parts?', 93547, 27602),
(16811, 0, 0, 'Enter the Proving Grounds', 74757, 27602),
(16514, 2, 0, 'Kalandrios, I would like to witness the Ritual of Binding again.', 79317, 27602),
(16595, 0, 0, 'Remember the Battle at the Stones of Prophecy.', 83478, 27602),
(16829, 0, 0, 'Give the order, Yrel. Destroy the gates and get us in there.', 85568, 27602),
(16825, 0, 0, 'Like it or not, we need to move ahead. What\'s the situation?', 85566, 27602), -- OptionBroadcastTextID: 85562 - 85566
(16823, 0, 0, 'I agree. A flanking maneuver will buy you the time you need to move most of our forces closer to Garrosh.', 85559, 27602), -- OptionBroadcastTextID: 85557 - 85559
(16586, 0, 0, 'Yrel, let\'s blow open those gates and take Grommashar.', 84079, 27602),
(16423, 1, 0, 'Thaelin, let\'s change this building into a corral.', 85701, 27602),
(17317, 0, 2, 'I need a ride.', 3409, 27602),
(16894, 5, 0, 'I\'m ready to fight in the Blood Championship.', 86399, 27602),
(18287, 0, 28, 'I would like to place a work order.', 83605, 27602),
(16916, 7, 1, 'What do we have in stock?', 92025, 27602),
(16452, 1, 1, 'I want to browse your goods.', 3370, 27602),
(16452, 0, 5, 'Make this inn your home.', 2822, 27602),
(16728, 2, 2, 'Show me where I can fly.', 12271, 27602),
(16728, 0, 0, 'Fly me to the Spirit Woods near Oshu\'gun.', 83811, 27602),
(16514, 1, 0, 'Kalandrios, I would like to witness the Ritual of Binding again.', 79317, 27602),
(16514, 0, 0, 'I am ready to begin the Ritual of Binding.', 83982, 27602),
(16492, 0, 0, 'I stand with you, Gar\'rok. Rest with honor.', 82719, 27602),
(16494, 0, 0, 'I wish to know the truth about Dahaka. What do you know of her death?', 82686, 27602),
(16653, 0, 0, 'I am ready to commune with the furies.', 82853, 27602),
(16732, 0, 0, 'Reel it in!', 84868, 27602),
(16904, 0, 0, 'Marybelle Walsh sent me to rescue you. Go and I\'ll protect you!', 86518, 27602),
(17357, 0, 0, 'The saberon attack is over. Go now, and rest in peace.', 91492, 27602),
(16467, 0, 0, 'What can you tell me about the Steamwheedle Preservation Society?', 82367, 27602),
(16416, 4, 0, 'I am ready to begin the fifth Trial of The Ring.', 81662, 27602),
(16416, 3, 0, 'I am ready to begin the fourth Trial of The Ring.', 81661, 27602),
(16416, 2, 0, 'I am ready to begin the third Trial of The Ring.', 81660, 27602),
(16416, 1, 0, 'I am ready to begin the second Trial of The Ring.', 81659, 27602),
(16416, 0, 0, 'I am ready to begin the first Trial of The Ring.', 81656, 27602),
(16569, 1, 1, 'I want to browse your goods.', 3370, 27602),
(16569, 0, 5, 'Make this inn your home.', 2822, 27602),
(16570, 0, 1, 'I want to browse your goods.', 3370, 27602),
(18167, 0, 1, 'I would like to buy from you.', 14967, 27602), -- OptionBroadcastTextID: 2583 - 6399 - 7142 - 9992 - 14967
(16721, 0, 0, 'Check for a pulse.', 84745, 27602),
(16597, 2, 0, 'I need a flight to the border of Nagrand.', 83511, 27602),
(16650, 0, 0, 'Show the schematic to Bryan.', 83978, 27602),
(16875, 1, 2, 'Show me where I can fly.', 12271, 27602),
(16875, 0, 0, 'Fly me to Talon Watch.', 86449, 27602),
(16832, 0, 5, 'Make this inn your home.', 2822, 27602),
(16640, 0, 0, 'Your prisoner is with me. He means your people no harm.', 83844, 27602),
(17043, 1, 1, 'Let me browse your goods.', 8097, 27602), -- OptionBroadcastTextID: 2823 - 7509 - 8097
(17043, 0, 5, 'Make this inn your home.', 2822, 27602),
(17201, 0, 1, 'I need reagents.', 89963, 27602),
(17107, 1, 3, 'Train me in Inscription.', 88801, 27602), -- OptionBroadcastTextID: 47113 - 88801
(17107, 0, 3, 'Train me in Archaeology.', 88800, 27602), -- OptionBroadcastTextID: 88647 - 88800
(16476, 0, 0, '\"Shadows gather...\"', 83412, 27602), -- OptionBroadcastTextID: 82307 - 83412
(16575, 0, 0, '\"Shadows gather...\"', 83412, 27602), -- OptionBroadcastTextID: 82307 - 83412
(16597, 10, 0, 'I am needed urgently at the Iron Docks.', 87474, 27602),
(16597, 9, 0, 'Please fly me to Spires of Arak.', 91501, 27602),
(16597, 1, 0, 'Take me to my base in Talador.', 83474, 27602),
(16688, 1, 1, 'Let me browse your goods.', 8097, 27602), -- OptionBroadcastTextID: 2823 - 7509 - 8097
(16688, 0, 5, 'Make this inn your home.', 2822, 27602),
(16597, 7, 0, 'I\'m responding to the Steamwheedle call for help. Take me to the Spires of Arak.', 88555, 27602),
(18677, 4, 1, 'Let me browse your goods.', 8097, 27602), -- OptionBroadcastTextID: 2823 - 7509 - 8097
(18677, 0, 0, 'How do I obtain spooky supplies and merry supplies?', 99089, 27602),
(17531, 0, 0, 'I need you to come on patrol with me.', 81638, 27602),
(17422, 0, 0, 'I need you to come on patrol with me.', 81638, 27602),
(17306, 5, 0, 'Legendary: Gul\'dan Ascendant', 95564, 27602),
(17306, 2, 0, 'Shadowmoon Valley: Darkness Falls', 90937, 27602),
(17306, 1, 0, 'Tanaan Jungle: A Taste of Iron', 90949, 27602),
(17306, 0, 0, 'Blasted Lands: Into the Portal', 90945, 27602),
(17319, 0, 1, 'Show me what contracts are available.', 92816, 27602),
(16998, 2, 1, 'I would like to buy from you.', 14967, 27602), -- OptionBroadcastTextID: 2583 - 6399 - 7142 - 9992 - 14967
(18322, 0, 1, 'Let me browse your goods.', 8097, 27602), -- OptionBroadcastTextID: 2823 - 7509 - 8097
(18566, 11, 0, 'Grant me a vision of Archimonde\'s fall at the Black Gate.', 121897, 27602),
(18566, 10, 0, 'Grant me a vision of the Destructor\'s Rise atop Hellfire Citadel.', 121896, 27602),
(18566, 9, 0, 'Grant me a vision of the Hellfire Citadel\'s Bastion of Shadows.', 121895, 27602),
(18566, 8, 0, 'Grant me a vision of the Hellfire Citadel\'s Halls of Blood.', 121894, 27602),
(18566, 7, 0, 'Grant me a vision of the Hellbreach, before the gates of Hellfire Citadel.', 121893, 27602),
(18566, 6, 0, 'Grant me a vision of Blackhand\'s Crucible within the Blackrock Foundry.', 121892, 27602),
(18566, 5, 0, 'Grant me a vision of the Blackrock Foundry\'s Iron Assembly.', 121891, 27602),
(18566, 4, 0, 'Grant me a vision of the Blackrock Foundry\'s Black Forge.', 121889, 27602),
(18566, 3, 0, 'Grant me a vision of the Blackrock Foundry\'s Slagworks.', 121890, 27602),
(18566, 2, 0, 'Grant me a vision of the Imperator\'s Rise atop Highmaul.', 121888, 27602),
(18566, 1, 0, 'Grant me a vision of the Arcane Sanctum of Highmaul.', 121887, 27602),
(18566, 0, 0, 'Grant me a vision of the Walled City of Highmaul.', 121886, 27602),
(17330, 1, 0, 'Me too!', 91476, 27602),
(17330, 0, 1, 'I want to browse your goods.', 3370, 27602),
(16518, 1, 1, 'I would like to buy from you.', 14967, 27404), -- OptionBroadcastTextID: 2583 - 6399 - 7142 - 9992 - 14967
(16518, 0, 0, 'Yes. I need you to help me operate that enormous tank.', 83004, 27404),
(16641, 0, 0, 'Khadgar has asked us to go distract the Eye of Kilrogg.', 83852, 27404),
(16863, 0, 0, 'FOR AZEROTH!', 94100, 27404), -- OptionBroadcastTextID: 85997 - 94100
(13843, 0, 0, 'I am here with Ban Bearheart, and we demand an audience with Taran Zhu!', 61677, 27377),
(13831, 1, 0, 'Alright, let\'s go up to the monastery.', 63457, 27377),
(13831, 0, 0, 'I\'m ready to leave. Let\'s go!', 63439, 27377),
(13836, 0, 0, 'Alright, I\'m ready to get back to the front.', 61502, 27377),
(13830, 1, 0, 'I need a kite to get up to the wall!', 61468, 27377),
(13830, 0, 2, 'I\'d like to take a kite somewhere.', 61467, 27377),
(13678, 0, 0, 'Let\'s get out of here.', 124915, 27377), -- OptionBroadcastTextID: 59706 - 85967 - 124915
(13681, 0, 0, 'Yes... why don\'t you \"escort\" me out of here.', 59730, 27377),
(13680, 0, 0, '...That\'s enough. Let\'s go.', 59728, 27377),
(13794, 0, 1, 'I would like to buy from you.', 14967, 27377), -- OptionBroadcastTextID: 2583 - 6399 - 7142 - 9992 - 14967
(13795, 1, 5, 'Make this inn your home.', 2822, 27377),
(13795, 0, 1, 'I would like to buy from you.', 14967, 27377), -- OptionBroadcastTextID: 2583 - 6399 - 7142 - 9992 - 14967
(13720, 0, 0, '<Unscrew the flask and offer it to her.>', 60198, 27377),
(13893, 0, 0, 'What is a \"luckydo\"?', 61779, 27377),
(13892, 0, 0, 'I want to ask something else.', 121489, 27377), -- OptionBroadcastTextID: 61781 - 121489
(13796, 0, 1, 'I would like to buy from you.', 14967, 27377), -- OptionBroadcastTextID: 2583 - 6399 - 7142 - 9992 - 14967
(15055, 2, 0, 'I\'d like to heal and revive my battle pets.', 64115, 27377),
(15055, 1, 1, 'I\'m looking for a lost companion.', 56613, 27377),
(13686, 0, 1, 'Let me browse your goods.', 8097, 27377), -- OptionBroadcastTextID: 2823 - 7509 - 8097
(13467, 2, 0, 'I\'ve changed my mind.', 57673, 27377),
(13467, 0, 0, 'Let\'s go.', 128698, 27377), -- OptionBroadcastTextID: 15894 - 57655 - 60204 - 62002 - 75830 - 77209 - 78160 - 78305 - 108064 - 125346 - 129809 - 129792 - 128698
(13462, 4, 2, 'Show me where I can fly.', 12271, 27377),
(13462, 3, 0, 'I need to meet up with Kang Bramblestaff.', 57650, 27377),
(13462, 1, 0, 'I need to meet up with Ken-Ken, the hozen.', 57649, 27377),
(13464, 2, 0, 'I\'ve changed my mind.', 57673, 27377),
(13464, 0, 0, 'Let\'s go.', 128698, 27377), -- OptionBroadcastTextID: 15894 - 57655 - 60204 - 62002 - 75830 - 77209 - 78160 - 78305 - 108064 - 125346 - 129809 - 129792 - 128698
(13745, 0, 0, 'What is happening here?', 95092, 27377), -- OptionBroadcastTextID: 60545 - 95092
(13301, 4, 0, 'Master, I wish to review my advanced training.', 57458, 27377),
(13301, 3, 0, 'Master, I wish to review my basic training.', 57434, 27377),
(13301, 2, 0, 'I\'ve done all that you\'ve asked of me. I\'m ready for the trial of stone.', 55823, 27377),
(13437, 0, 0, 'Yes, the one with the eggs.', 57459, 27377),
(13301, 1, 0, 'My fists are ready. Bring on the trial of wood.', 55822, 27377),
(13301, 0, 0, 'I\'m ready for the trial of bamboo.', 55821, 27377),
(13310, 1, 0, 'Yes, they\'re right here. Let\'s go.', 55951, 27377),
(13310, 0, 0, 'Loon Mai has issued evacuation orders.', 55941, 27377), -- OptionBroadcastTextID: 55923 - 55933 - 55941
(13318, 0, 0, 'Yes, Commander Mai sent me, and I carry his evacuation orders.', 55928, 27377),
(13317, 0, 0, 'Yes, Commander Mai sent me, and I carry his evacuation orders.', 55928, 27377),
(13320, 0, 0, 'Loon Mai has issued evacuation orders.', 55941, 27377), -- OptionBroadcastTextID: 55923 - 55933 - 55941
(13316, 0, 0, 'Loon Mai has issued evacuation orders.', 55941, 27377), -- OptionBroadcastTextID: 55923 - 55933 - 55941
(13311, 0, 0, 'Loon Mai has issued evacuation orders.', 55941, 27377), -- OptionBroadcastTextID: 55923 - 55933 - 55941
(13748, 0, 0, 'I understand.', 97920, 27377), -- OptionBroadcastTextID: 53318 - 60548 - 97920
(13747, 0, 0, 'What happened to the wall, anyway?', 60547, 27377),
(13746, 0, 0, 'Shado-Pan?', 60546, 27377),
(13424, 0, 0, '<Try shaking Hemet.>', 57262, 27377),
(14795, 1, 1, 'I would like to buy from you.', 14967, 27377), -- OptionBroadcastTextID: 2583 - 6399 - 7142 - 9992 - 14967
(14795, 0, 3, 'Train me in Engineering.', 47119, 27377),
(14324, 0, 3, 'Train me in Skinning.', 47117, 27377),
(13379, 1, 0, 'Let\'s do this, Chen.', 56890, 27377),
(13378, 0, 0, 'I\'ll help.', 56889, 27377),
(13398, 0, 0, '<Crack your knuckles and nod your head.>', 56980, 27377),
(13622, 10, 0, 'How is my relationship with Tina Mudclaw?', 59186, 27377),
(13622, 9, 0, 'How is my relationship with Sho?', 59185, 27377),
(13622, 8, 0, 'How is my relationship with Old Hillpaw?', 59184, 27377),
(13622, 7, 0, 'How is my relationship with Haohan Mudclaw?', 59183, 27377),
(13622, 6, 0, 'How is my relationship with Jogu the Drunk?', 59182, 27377),
(13622, 5, 0, 'How is my relationship with Gina Mudclaw?', 59181, 27377),
(13622, 4, 0, 'How is my relationship with Farmer Fung?', 59180, 27377),
(13622, 3, 0, 'How is my relationship with Fish Fellreed?', 59179, 27377),
(13622, 2, 0, 'How is my relationship with Ella?', 59178, 27377),
(13622, 1, 0, 'How is my relationship with Chee Chee?', 59177, 27377),
(13470, 5, 1, 'I would like to buy from you.', 14967, 27377), -- OptionBroadcastTextID: 2583 - 6399 - 7142 - 9992 - 14967
(13470, 2, 0, 'Where does everyone live?', 57739, 27377),
(13470, 1, 0, 'What kind of gifts do you like?', 58603, 27377),
(13470, 0, 0, 'What can you tell me about gifts?', 57703, 27377),
(12135, 0, 0, 'Well, let\'s get to it then.', 46426, 27326),
(12136, 0, 0, 'And I take it you\'re going again...', 46424, 27326),
(12137, 0, 0, 'You seem very certain.', 46422, 27326),
(12138, 0, 0, 'Yeah...', 46420, 27326),
(11522, 1, 1, 'Do you have any supplies?', 45532, 27178), -- OptionBroadcastTextID: 41415 - 45532
(11522, 0, 5, 'May I rest here?', 41414, 27178),
(11489, 0, 0, 'Who are you, friend?', 40025, 27178),
(11514, 0, 0, 'Are there any weaknesses we can exploit? Any holes in the naga defenses?', 41378, 27178),
(11510, 0, 0, 'Did you see Captain Taylor and his men?', 41376, 27178),
(11511, 0, 0, 'How did you escape, Pollard?', 41372, 27178),
(11508, 0, 0, 'What can you tell me about your captors?', 41370, 27178),
(11509, 0, 0, 'How did you get down here?', 41707, 27178), -- OptionBroadcastTextID: 41368 - 41707
(11444, 0, 0, 'Make for that cave to the west. It\'s safe and dry.', 40804, 27178),
(12213, 0, 0, 'The perimeter is secure, commander.', 47376, 27101),
(18536, 0, 27, 'Greetings and salutations, hero!  I have the latest news from both continents and points beyond for your consideration.', 9551, 27791),
(18486, 4, 28, 'I would like to build a battleship.', 95672, 27791),
(18486, 3, 28, 'I would like to build a transport.', 95673, 27791),
(18486, 1, 28, 'I would like to build a destroyer.', 98364, 27791),
(18253, 0, 2, 'Show me where I can fly.', 12271, 27791),
(18599, 0, 1, 'I would like to buy from you.', 14967, 27791), -- OptionBroadcastTextID: 2583 - 6399 - 7142 - 9992 - 14967
(18437, 0, 1, 'I need reagents.', 89963, 27791),
(18335, 1, 0, 'How defended is that Iron Horde tunnel?', 94827, 27791),
(18335, 0, 0, 'Arakkoa in Tanaan? Tell me more of Aktar\'s Watch.', 94073, 27791),
(18331, 2, 0, 'What do you know of Zorammarsh?', 94825, 27791),
(18331, 1, 0, 'What is happening at the Temple of Sha\'naar?', 94068, 27791),
(18331, 0, 0, 'Tell me of Zeth\'Gol.', 94064, 27791),
(18333, 0, 0, 'What is happening at the Temple of Sha\'naar?', 94068, 27791),
(18412, 1, 0, 'What do those challenge totems you sell do?', 94792, 27791),
(18412, 0, 1, 'Let me browse your goods.', 8097, 27791), -- OptionBroadcastTextID: 2823 - 7509 - 8097
(18620, 0, 0, 'Yes I would! You, sir, are a gentleman and a ... Skoller.', 97090, 27791),
(18228, 0, 0, 'You are Lagar? I bring word from a shaman of your order. He says... Gul\'dan knows. May I ask what this means?', 92994, 27791),
(18670, 0, 1, 'I would like to buy from you.', 14967, 27791), -- OptionBroadcastTextID: 2583 - 6399 - 7142 - 9992 - 14967
(17542, 0, 0, 'I need you to come on patrol with me.', 81638, 27602),
(17038, 0, 1, 'Let me browse your goods.', 8097, 27602), -- OptionBroadcastTextID: 2823 - 7509 - 8097
(16353, 0, 0, 'What can you tell me about this place?', 81043, 27602), -- OptionBroadcastTextID: 22288 - 81043
(16367, 0, 0, 'I am ready to return to the Jorune Mine.', 81135, 27602),
(16357, 0, 0, 'I am ready to confront Kaelynara.', 81134, 27602),
(16312, 0, 0, 'Do you need help?', 80425, 27602),
(16448, 0, 0, 'So be it.', 114186, 27602), -- OptionBroadcastTextID: 55744 - 65419 - 81967 - 107195 - 112004 - 114186
(16447, 0, 0, 'Very well. Let us fight.', 81956, 27602), -- OptionBroadcastTextID: 68424 - 81956
(16692, 0, 0, 'Bring the Constructs back here.', 92565, 27602),
(16850, 0, 0, 'Then let\'s hurry!', 85801, 27602),
(16814, 0, 0, 'I am ready to teleport to the ship.', 82591, 27602),
(16878, 0, 0, 'Begin your spell.  I\'ll protect you!', 86124, 27602),
(17094, 0, 0, 'Thanks. I\'ll meet them at the docks.', 88735, 27602),
(17321, 0, 1, 'Let me browse your goods.', 8097, 27602), -- OptionBroadcastTextID: 2823 - 7509 - 8097
(17541, 0, 0, 'I need you to come on patrol with me.', 81638, 27602),
(17443, 0, 0, 'I need you to come on patrol with me.', 81638, 27602),
(17511, 0, 0, 'I need you to come on patrol with me.', 81638, 27602),
(18498, 0, 1, 'I would like to buy outdated equipment from you.', 95561, 27602),
(18497, 0, 1, 'I would like to buy outdated equipment from you.', 95561, 27602),
(18492, 0, 1, 'I would like to buy outdated equipment from you.', 95561, 27602),
(18489, 0, 1, 'I would like to buy outdated equipment from you.', 95561, 27602),
(17183, 0, 1, 'Let me browse your goods.', 8097, 27602), -- OptionBroadcastTextID: 2823 - 7509 - 8097
(17148, 2, 0, 'Now show me \"Magnuum!\"', 89201, 27602),
(17148, 1, 0, 'Okay, how about \"Azure Steel?\"', 89200, 27602),
(17148, 0, 0, 'Show me \"Le Talbuk!\"', 89199, 27602),
(17182, 0, 1, 'Let me browse your goods.', 8097, 27602), -- OptionBroadcastTextID: 2823 - 7509 - 8097
(17152, 0, 3, 'Train me in Skinning.', 47117, 27602),
(17153, 0, 3, 'Train me in Blacksmithing.', 47110, 27602),
(17157, 0, 3, 'Train me in Fishing.', 89249, 27602),
(17131, 0, 1, 'What recipes do you sell?', 35243, 27602),
(17130, 0, 3, 'Train me in Enchanting.', 47111, 27602),
(17334, 11, 0, 'Item Upgrade', 105470, 27602),
(17334, 10, 0, 'Vendor', 44612, 27602),
(17334, 9, 0, 'Transmogrification & Void Storage', 66651, 27602),
(17334, 8, 0, 'Stable Master', 45383, 27602), -- OptionBroadcastTextID: 8508 - 8511 - 8518 - 8524 - 8525 - 8529 - 8534 - 8536 - 8539 - 8542 - 15228 - 19208 - 45383
(17334, 7, 0, 'Profession Trainer', 45382, 27602), -- OptionBroadcastTextID: 2869 - 3430 - 4896 - 5112 - 5352 - 5916 - 6635 - 6912 - 7022 - 7095 - 15250 - 19210 - 45382
(17334, 6, 0, 'Pet Battle Trainer', 66645, 27602),
(17334, 5, 0, 'Other Continents', 129194, 27602), -- OptionBroadcastTextID: 5914 - 47507 - 129389 - 129362 - 129235 - 129224 - 129194
(17334, 4, 0, 'Mailbox', 45381, 27602), -- OptionBroadcastTextID: 4895 - 5093 - 5336 - 5514 - 5912 - 6397 - 15226 - 19204 - 45381
(17334, 3, 0, 'Inn', 44629, 27602), -- OptionBroadcastTextID: 5513 - 5911 - 6396 - 6633 - 6910 - 15224 - 19202 - 32166 - 44629
(17334, 2, 0, 'Flight Master', 45379, 27602), -- OptionBroadcastTextID: 2863 - 4889 - 6632 - 19203 - 45379
(17334, 1, 0, 'Bank', 78584, 27602), -- OptionBroadcastTextID: 3426 - 5908 - 6631 - 6907 - 6987 - 15214 - 19201 - 32167 - 44628 - 78584
(17334, 0, 0, 'Auction House', 44627, 27602), -- OptionBroadcastTextID: 5316 - 5423 - 5515 - 5913 - 6369 - 15208 - 32174 - 44627
(17312, 0, 1, 'I would like to buy from you.', 14967, 27602), -- OptionBroadcastTextID: 2583 - 6399 - 7142 - 9992 - 14967
(18324, 0, 1, 'I\'d like to purchase Seals of Tempered Fate.', 96895, 27602);

INSERT INTO `gossip_menu_option` (`MenuId`, `OptionIndex`, `OptionIcon`, `OptionText`, `OptionBroadcastTextId`, `VerifiedBuild`) VALUES
(17044, 0, 1, 'I would like to buy from you.', 14967, 27602), -- OptionBroadcastTextID: 2583 - 6399 - 7142 - 9992 - 14967
(17126, 0, 1, 'Let me browse your goods.', 8097, 27602), -- OptionBroadcastTextID: 2823 - 7509 - 8097
(18275, 0, 0, 'Why are you here?', 93595, 27602), -- OptionBroadcastTextID: 3582 - 26310 - 93595
(18276, 0, 0, 'Would you like to join our cause?', 93588, 27602),
(17049, 1, 0, 'I\'d like to heal and revive my battle pets.', 64115, 27602),
(17128, 0, 5, 'Make this inn your home.', 2822, 27602),
(17372, 4, 0, 'Trade Supplies', 45445, 27602), -- OptionBroadcastTextID: 32719 - 45445
(17372, 3, 0, 'Reputation Vendors', 91526, 27602),
(17372, 2, 0, 'General Goods', 45444, 27602), -- OptionBroadcastTextID: 32712 - 45444
(17372, 1, 0, 'Auction House', 44627, 27602), -- OptionBroadcastTextID: 5316 - 5423 - 5515 - 5913 - 6369 - 15208 - 32174 - 44627
(17372, 0, 0, 'Apexis Shard Vendor', 91525, 27602),
(17349, 14, 0, 'Tailoring', 52077, 27602), -- OptionBroadcastTextID: 2951 - 3469 - 4871 - 5144 - 5380 - 5900 - 6629 - 6717 - 6787 - 6956 - 7035 - 7121 - 15275 - 32148 - 45760 - 52077
(17349, 13, 0, 'Skinning', 106243, 27602), -- OptionBroadcastTextID: 2948 - 3471 - 4869 - 5140 - 5376 - 5899 - 6628 - 6716 - 6786 - 6955 - 7034 - 7118 - 15273 - 19237 - 45770 - 52076 - 106243
(17349, 12, 0, 'Mining', 78976, 27602), -- OptionBroadcastTextID: 2944 - 3468 - 4868 - 5138 - 5898 - 6627 - 6714 - 6785 - 6954 - 7033 - 15271 - 32147 - 45769 - 51348 - 78976
(17349, 11, 0, 'Leatherworking', 52071, 27602), -- OptionBroadcastTextID: 2947 - 3467 - 4866 - 5133 - 5371 - 5897 - 6626 - 6713 - 6784 - 6953 - 7032 - 7115 - 15269 - 19236 - 45759 - 52071
(17349, 10, 0, 'Jewelcrafting', 45758, 27602), -- OptionBroadcastTextID: 15267 - 18338 - 19235 - 44647 - 45758
(17349, 9, 0, 'Inscription', 48811, 27602), -- OptionBroadcastTextID: 31542 - 32146 - 45757 - 48811
(17349, 8, 0, 'Herbalism', 45768, 27602), -- OptionBroadcastTextID: 2950 - 3466 - 4865 - 5129 - 5130 - 5370 - 5896 - 6625 - 6712 - 6783 - 6952 - 7031 - 7112 - 15265 - 32145 - 45434 - 45768
(17349, 7, 0, 'Fishing', 99684, 27602), -- OptionBroadcastTextID: 3005 - 3465 - 4864 - 5127 - 5368 - 5895 - 6624 - 6711 - 6782 - 6951 - 7030 - 7109 - 15263 - 32144 - 45436 - 45767 - 99684
(17349, 6, 0, 'First Aid', 52066, 27602), -- OptionBroadcastTextID: 2949 - 3464 - 4863 - 5125 - 5366 - 5894 - 6623 - 6710 - 6781 - 6950 - 7029 - 7106 - 15261 - 19238 - 45765 - 52066
(17349, 5, 0, 'Engineering', 51347, 27602), -- OptionBroadcastTextID: 2943 - 4976 - 5123 - 5893 - 6622 - 6780 - 6949 - 7028 - 15259 - 32143 - 45756 - 51347
(17349, 4, 0, 'Enchanting', 52063, 27602), -- OptionBroadcastTextID: 3006 - 3463 - 4862 - 5121 - 5363 - 5892 - 6621 - 6709 - 6779 - 6948 - 7027 - 7103 - 15257 - 19234 - 45755 - 52063
(17349, 3, 0, 'Cooking', 45763, 27602), -- OptionBroadcastTextID: 2945 - 3462 - 4861 - 5119 - 5356 - 5891 - 6620 - 6708 - 6778 - 6947 - 7026 - 7100 - 16029 - 19233 - 45432 - 45763
(17349, 2, 0, 'Blacksmithing', 51346, 27602), -- OptionBroadcastTextID: 2942 - 3461 - 4860 - 5117 - 5890 - 6619 - 6707 - 6777 - 6946 - 7025 - 15255 - 19249 - 45754 - 51346
(17349, 1, 0, 'Archaeology', 44649, 27602),
(17349, 0, 0, 'Alchemy', 52058, 27602), -- OptionBroadcastTextID: 2952 - 3460 - 4859 - 5114 - 5354 - 5362 - 5889 - 6618 - 6706 - 6776 - 6945 - 7024 - 7097 - 15252 - 19232 - 45753 - 52058
(17348, 2, 0, 'Stormwind', 91470, 27602), -- OptionBroadcastTextID: 25947 - 91470
(17348, 1, 0, 'Ironforge', 129104, 27602), -- OptionBroadcastTextID: 25944 - 91468 - 129104
(17348, 0, 0, 'Darnassus', 129386, 27602), -- OptionBroadcastTextID: 25942 - 91466 - 129386
(17344, 2, 0, 'Town Hall', 91463, 27602),
(17344, 1, 0, 'Inn', 44629, 27602), -- OptionBroadcastTextID: 5513 - 5911 - 6396 - 6633 - 6910 - 15224 - 19202 - 32166 - 44629
(17344, 0, 0, 'Bank', 78584, 27602), -- OptionBroadcastTextID: 3426 - 5908 - 6631 - 6907 - 6987 - 15214 - 19201 - 32167 - 44628 - 78584
(16597, 5, 0, 'Take me to Stormshield in Ashran.', 87595, 27602),
(17009, 1, 0, 'I need you to come on patrol with me.', 81638, 27602),
(17000, 4, 0, 'Heard any pet battle news out of Tanaan Jungle?', 96547, 27602), -- OptionBroadcastTextID: 96385 - 96547
(17000, 3, 0, 'Why are you called the Lioness?', 87407, 27602),
(17000, 2, 1, 'Any pet stuff for sale?', 87415, 27602),
(17000, 0, 0, 'I\'d like to heal and revive my battle pets.', 64115, 27602),
(17271, 6, 1, 'What do we have in stock?', 92025, 27602),
(17271, 3, 0, 'Prepare to battle the Shadowmoon clan.', 86828, 27602), -- OptionBroadcastTextID: 86825 - 86828
(17535, 0, 0, 'I need you to come on patrol with me.', 81638, 27602),
(17308, 0, 0, 'Listen to the Prophet\'s final message.', 90923, 27602),
(17089, 1, 1, 'I want to browse your goods.', 3370, 27602),
(17089, 0, 5, 'Make this inn your home.', 2822, 27602),
(16292, 0, 0, 'I am ready to join the attack against the Iron Horde.', 79399, 27602),
(17426, 0, 28, 'I would like to place a work order.', 83605, 27547),
(16236, 0, 0, 'Who are you?', 97339, 27547), -- OptionBroadcastTextID: 25092 - 38470 - 47091 - 47632 - 62792 - 65124 - 79414 - 97339
(16872, 4, 0, 'I don\'t have the 10 timber required to place a work order. Where can I find more timber?', 85919, 27547),
(16739, 0, 0, 'I need you to come on patrol with me.', 81638, 27547),
(16744, 1, 0, 'I\'d like to speak to the others.', 85038, 27547),
(16744, 0, 0, 'Onaala, I choose you!', 85040, 27547),
(16745, 1, 0, 'I\'d like to speak to the others.', 85038, 27547),
(16745, 0, 0, 'Andren, I choose you!', 85036, 27547),
(16743, 1, 0, 'I\'d like to speak to the others.', 85038, 27547),
(16743, 0, 0, 'Chel, I choose you!', 85039, 27547),
(16690, 0, 0, 'I am ready. Begin the ritual, Exarch.', 84452, 27547),
(16526, 1, 0, 'How exactly did you get to Draenor, anyway?', 83335, 27547),
(16526, 0, 0, 'Exotic pets? These all seem pretty ordinary...', 83073, 27547),
(16999, 0, 1, 'Let me browse your goods.', 8097, 27547), -- OptionBroadcastTextID: 2823 - 7509 - 8097
(16986, 0, 3, 'I\'m interested in fishing these savage lands.', 82737, 27547),
(16994, 0, 28, 'Can you refine this draenic stone into ore for me?', 87263, 27547),
(17069, 2, 1, 'I want to browse your goods.', 3370, 27547),
(16862, 0, 0, 'You look like an able fisherman, do you think you can help us out?\n\nWe have established a small garrison nearby, but we are finding it difficult to feed our troops. Any fishing advice you could give us would really help.', 0, 27547),
(17005, 0, 0, 'Nevermind!', 87414, 27547),
(16464, 0, 1, 'Let me browse your goods.', 8097, 27547), -- OptionBroadcastTextID: 2823 - 7509 - 8097
(17199, 0, 1, 'Let me browse your goods.', 8097, 27547), -- OptionBroadcastTextID: 2823 - 7509 - 8097
(16966, 0, 28, 'Can you grow these draenic seeds into herbs for me?', 86940, 27547),
(16962, 1, 1, 'I want to browse your goods.', 3370, 27547),
(16561, 0, 1, 'Let me browse your goods.', 8097, 27547), -- OptionBroadcastTextID: 2823 - 7509 - 8097
(7742, 1, 0, 'Khadgar, let\'s go over what happened when Garona attacked.', 81168, 27547), -- OptionBroadcastTextID: 76001 - 81168
(7742, 0, 0, 'Remember when we compelled the All-Seeing Eye to spy upon the Shadow Council?', 75144, 27547),
(16609, 0, 0, 'Very good, Zipfizzle. Move out.', 83641, 27547),
(15802, 0, 0, 'Begin the compulsion of the All-Seeing Eye.', 75188, 27547),
(17235, 3, 0, 'Blessing of K\'ure', 90140, 27547),
(17235, 2, 0, 'Blessing of K\'ara', 90170, 27547),
(17235, 1, 0, 'Blessing of D\'ore', 90169, 27547),
(17235, 0, 0, 'Blessing of A\'dal', 90171, 27547),
(16598, 0, 0, 'Gather Shelly\'s report.', 83504, 27547),
(16613, 0, 0, 'Time to get back to work.', 83683, 27547),
(16998, 1, 0, 'I have lost my garrison hearthstone, can you give me another?', 87395, 27547),
(16871, 0, 0, 'We have everything we need. It\'s time to build the garrison.', 81731, 27547),
(13847, 6, 0, 'Grant me your assistance, Wind-Reaver. [Klaxxi Enhancement]', 62448, 27377),
(13847, 4, 0, 'Please fly me to Zan\'vess.', 64747, 27377),
(14314, 0, 0, 'Grant me your assistance, Manipulator. [Klaxxi Augmentation]', 66189, 27377),
(14272, 0, 0, 'Grant me your assistance, Bloodseeker. [Klaxxi Augmentation]', 62565, 27377),
(14271, 0, 0, 'Grant me your assistance, Prime. [Klaxxi Augmentation]', 62562, 27377),
(14655, 0, 0, 'Grant me your assistance, Iyyokuk. [Klaxxi Enhancement]', 66186, 27377),
(14656, 0, 0, 'Grant me your assistance, Locust. [Klaxxi Augmentation]', 66188, 27377),
(13888, 0, 0, 'Grant me your assistance, Malik. [Klaxxi Enhancement]', 63617, 27377),
(14398, 0, 0, 'Deck Boss said you needed some help.', 64125, 27377),
(14663, 0, 1, 'I would like to buy from you.', 14967, 27377), -- OptionBroadcastTextID: 2583 - 6399 - 7142 - 9992 - 14967
(14044, 2, 0, 'What are you doing here?', 123345, 27377), -- OptionBroadcastTextID: 35775 - 38471 - 57803 - 57891 - 66486 - 81341 - 86824 - 123345
(14275, 0, 0, 'The forked blade is ready, and we have given our gift. Please perform your incantation.', 62593, 27377),
(14044, 1, 0, 'Have you seen anybody named Stormstout come through here?', 62382, 27377),
(14043, 1, 0, 'Is your name really Stormstout?', 62374, 27377),
(14046, 1, 0, 'Have you seen any Stormstouts here in the Brewgarden?', 62384, 27377),
(14484, 0, 0, 'I\'m ready to help you find your weapon.', 68817, 27377),
(13847, 1, 0, 'Please fly me to the Clutches of Shek\'zeer', 62449, 27377),
(14667, 0, 0, 'What was your old job?', 66490, 27377),
(14666, 0, 0, 'Why is that?', 66489, 27377), -- OptionBroadcastTextID: 41908 - 66489
(14665, 0, 0, 'And you make beer out of it.', 66488, 27377),
(14664, 0, 0, 'Beer made with sap? That sounds...', 66487, 27377),
(14807, 1, 1, 'I would like to buy from you.', 14967, 27377), -- OptionBroadcastTextID: 2583 - 6399 - 7142 - 9992 - 14967
(14807, 0, 5, 'Make this inn your home.', 2822, 27377),
(14641, 0, 3, 'Train me in Alchemy.', 47109, 27377),
(13847, 0, 0, 'Take me to Klaxxi\'vess.', 62093, 27377),
(15570, 0, 0, 'I\'m ready to go.', 126740, 27377), -- OptionBroadcastTextID: 72984 - 72985 - 126740
(13781, 0, 0, 'I have orders for you to return to the battlefront.', 60910, 27377),
(13799, 0, 0, 'I have orders for you to return to the battlefront.', 60910, 27377),
(13798, 0, 0, 'I have orders for you to return to the battlefront.', 60910, 27377),
(13797, 0, 0, 'I have orders for you to return to the battlefront.', 60910, 27377),
(13731, 0, 0, '<Remove the spear from Orbiss\' side.>', 60318, 27377),
(13739, 1, 0, 'I need another Totem of Harmony.', 60568, 27377),
(13739, 2, 0, 'I am ready to begin the ritual.', 103586, 27377), -- OptionBroadcastTextID: 60578 - 103586
(13733, 0, 0, 'Examine the body.', 60367, 27377),
(14636, 0, 1, 'Let me browse your goods.', 8097, 27377), -- OptionBroadcastTextID: 2823 - 7509 - 8097
(14599, 0, 0, 'Let\'s find out!', 65517, 27377),
(13753, 0, 1, 'Let me browse your goods.', 8097, 27377), -- OptionBroadcastTextID: 2823 - 7509 - 8097
(13810, 0, 5, 'Please, sit and make yourself comfortable.', 16966, 27377), -- OptionBroadcastTextID: 14352 - 16966
(15041, 1, 3, 'Train me in Mining.', 47116, 27377),
(15041, 0, 3, 'Train me in Blacksmithing.', 47110, 27377),
(14993, 1, 3, 'Train me in Inscription.', 88801, 27377), -- OptionBroadcastTextID: 47113 - 88801
(14993, 0, 3, 'Train me in Herbalism.', 47112, 27377),
(14992, 1, 3, 'Train me in Skinning.', 47117, 27377),
(14992, 0, 3, 'Train me in Leatherworking.', 47115, 27377),
(14986, 1, 1, 'What brews do you have available?', 67501, 27377),
(14986, 0, 3, 'Train me.', 3266, 27377),
(14994, 0, 3, 'Train me in First Aid.', 66761, 27377),
(14867, 0, 0, 'I\'m ready to leave.', 60252, 27377),
(14288, 0, 0, 'Where have the Thunder King\'s Remains been taken?!', 63379, 27377),
(14326, 0, 1, 'I would like to buy from you.', 14967, 27377), -- OptionBroadcastTextID: 2583 - 6399 - 7142 - 9992 - 14967
(14304, 0, 0, 'I\'ll cover your post. Go rest and be with your family.', 63477, 27377),
(14305, 0, 0, 'I\'ll cover your post. Go rest and be with your family.', 63477, 27377),
(14325, 1, 1, 'I would like to buy from you.', 14967, 27377), -- OptionBroadcastTextID: 2583 - 6399 - 7142 - 9992 - 14967
(14325, 0, 5, 'Make this inn your home.', 2822, 27377),
(14597, 0, 1, 'How may I help you?', 113783, 27377), -- OptionBroadcastTextID: 30864 - 32778 - 32779 - 32780 - 53142 - 53144 - 58309 - 61023 - 61839 - 62303 - 98955 - 113783
(13761, 0, 0, 'I\'m ready to leave.', 60252, 27377),
(13760, 0, 0, 'Have you noticed anything strange happening around Zouchin Village?', 60780, 27377),
(13759, 0, 0, 'I\'m ready to leave.', 60252, 27377),
(13724, 0, 0, 'I\'m ready to leave.', 60252, 27377),
(13723, 0, 0, 'Go ahead with the binding, Cho.', 60721, 27377),
(14640, 0, 1, 'I would like to buy from you.', 14967, 27377), -- OptionBroadcastTextID: 2583 - 6399 - 7142 - 9992 - 14967
(13665, 0, 0, 'Let\'s go, Miss Fanny.', 59610, 27377),
(13690, 0, 0, 'Can you increase my swim speed again?', 59852, 27377),
(14039, 1, 1, 'I would like to buy from you.', 14967, 27377), -- OptionBroadcastTextID: 2583 - 6399 - 7142 - 9992 - 14967
(14039, 0, 5, 'Make this inn your home.', 2822, 27377),
(14648, 1, 1, 'I would like to buy from you.', 14967, 27377), -- OptionBroadcastTextID: 2583 - 6399 - 7142 - 9992 - 14967
(14648, 0, 25, 'Queue for Unga Ingoo.', 64700, 27377),
(13713, 0, 0, 'What is this place?', 136659, 27377), -- OptionBroadcastTextID: 18411 - 39050 - 53647 - 60157 - 66591 - 94147 - 136659
(13714, 1, 0, 'I see.', 136544, 27377), -- OptionBroadcastTextID: 17156 - 18744 - 54388 - 60156 - 95411 - 106720 - 119172 - 136544
(13460, 0, 0, '<Try to untie Lyalia.>', 57630, 27377),
(13440, 0, 0, 'Why were you travelling to the Crane Temple?', 57792, 27377),
(13494, 0, 0, 'Mantid?', 57794, 27377),
(13455, 1, 0, 'Did you know that Lin found the Hidden Master? He\'s in Paoquan Hollow.', 68821, 27377),
(13611, 0, 0, '<Reach out to touch Chi-Ji.>', 59163, 27377),
(13537, 0, 0, 'How did you end up here?', 68261, 27377),
(13535, 0, 0, 'How did you end up here?', 68261, 27377),
(13468, 0, 0, 'I\'m ready, Koro.', 57913, 27377),
(15091, 0, 0, 'Why didn\'t you return to Stormwind with the SI:7?', 68264, 27377),
(13454, 0, 0, 'What are you doing here?', 123345, 27377), -- OptionBroadcastTextID: 35775 - 38471 - 57803 - 57891 - 66486 - 81341 - 86824 - 123345
(13446, 0, 0, 'What are you doing here?', 123345, 27377), -- OptionBroadcastTextID: 35775 - 38471 - 57803 - 57891 - 66486 - 81341 - 86824 - 123345
(13455, 0, 0, 'Join me!', 56954, 27377),
(13189, 0, 0, 'Attempt to free Na Lek from his prison.', 56956, 27377),
(13488, 1, 0, 'Did you know that Lin found the Hidden Master? He\'s in Paoquan Hollow.', 68821, 27377),
(14916, 0, 0, 'Wow, Duyi. What have you got there?', 67143, 27377),
(14917, 0, 0, 'Thank you, Maolin.', 67147, 27377),
(14310, 1, 3, 'Train me.', 3266, 27377),
(14310, 0, 1, 'I want to browse your goods.', 3370, 27377),
(14333, 0, 0, 'What are you doing so far from home?', 63799, 27377),
(13491, 1, 0, 'What is wrong with the portal?', 57798, 27377),
(13499, 0, 1, 'I would like to buy from you.', 14967, 27377), -- OptionBroadcastTextID: 2583 - 6399 - 7142 - 9992 - 14967
(13519, 0, 0, 'Take the supplies.', 58107, 27377),
(13384, 0, 0, 'How did you get here?', 57304, 27377), -- OptionBroadcastTextID: 57201 - 57304
(13419, 0, 0, 'I have a different question.', 62620, 27377),
(13351, 2, 0, 'Please tell me about Zhu\'s legacy.', 57053, 27377),
(13403, 0, 0, 'Longbrow? Does that mean Yi-Mo is a descendant of Zhu?!', 57054, 27377),
(13387, 2, 0, 'Did you know that Lin found the Hidden Master? He\'s in Paoquan Hollow.', 68821, 27377),
(13351, 0, 0, 'Mei, do you have any idea where I can find salt around here?', 56986, 27377),
(13354, 1, 0, 'I don\'t have time for this. Move your ass or I\'ll move it for you.', 56553, 27377),
(13354, 0, 0, 'You have your whole life ahead of you.', 56557, 27377),
(13353, 1, 0, 'You have your whole life ahead of you.', 56557, 27377),
(13353, 0, 0, 'Please, Yi-Mo: your aunt\'s worried sick about you.', 56552, 27377),
(13355, 1, 0, 'I don\'t have time for this. Move your ass or I\'ll move it for you.', 56553, 27377),
(13355, 0, 0, 'Please, Yi-Mo: your aunt\'s worried sick about you.', 56552, 27377),
(14050, 1, 1, 'Let me browse your goods.', 8097, 27377), -- OptionBroadcastTextID: 2823 - 7509 - 8097
(14050, 0, 5, 'Make this inn your home.', 2822, 27377),
(13334, 0, 0, 'What weeds?', 56221, 27377),
(13334, 2, 0, 'Can I buy some hops from you?', 56243, 27377),
(13850, 0, 0, 'I\'m ready to go!', 56189, 27377), -- OptionBroadcastTextID: 23162 - 56189
(13850, 2, 0, 'I\'m helping a friend brew some beer, and we need hops. Do you have any to spare?', 56242, 27377),
(13332, 0, 0, 'What kind of gifts do you like?', 58603, 27377),
(13593, 0, 0, 'What kind of gifts do you like?', 58603, 27377),
(13338, 0, 0, 'What kind of gifts do you like?', 58603, 27377),
(13853, 1, 0, 'Do you have any hops you can spare?', 56244, 27377),
(13594, 0, 0, 'What kind of gifts do you like?', 58603, 27377),
(13409, 1, 0, 'I\'m ready to go, Mudmug.', 57599, 27377),
(13445, 2, 0, 'Yoon, I need some farming advice.', 59501, 27377),
(13653, 11, 0, 'Can I replace something I\'ve already planted?', 68850, 27377),
(13653, 10, 0, 'My crop is Growing... now what?', 59688, 27377),
(13653, 9, 0, 'How do I deal with Stubborn weeds?', 59526, 27377),
(13653, 8, 0, 'How do I deal with Occupied soil?', 59525, 27377),
(13653, 7, 0, 'How do I care for Tangled crops?', 59510, 27377),
(13653, 6, 0, 'How do I care for Runty crops?', 59509, 27377),
(13653, 5, 0, 'How do I care for Wild crops?', 59508, 27377),
(13653, 4, 0, 'How do I care for Smothered crops?', 59507, 27377),
(13653, 3, 0, 'How do I care for Alluring crops?', 59506, 27377),
(13653, 2, 0, 'How do I care for Wiggling crops?', 59505, 27377),
(13653, 1, 0, 'How do I care for Infested crops?', 59504, 27377),
(13653, 0, 0, 'How do I care for Parched crops?', 59503, 27377),
(15156, 0, 0, 'I have another question...', 59523, 27377),
(13663, 0, 0, 'I have another question...', 59523, 27377),
(13662, 0, 0, 'I have another question...', 59523, 27377),
(13661, 0, 0, 'I have another question...', 59523, 27377),
(13660, 0, 0, 'I have another question...', 59523, 27377),
(13659, 0, 0, 'I have another question...', 59523, 27377),
(13658, 0, 0, 'I have another question...', 59523, 27377),
(13657, 0, 0, 'I have another question...', 59523, 27377),
(13656, 0, 0, 'I have another question...', 59523, 27377),
(13655, 0, 0, 'I have another question...', 59523, 27377),
(13654, 0, 0, 'I have another question...', 59523, 27377),
(13642, 1, 1, 'Let me browse your goods.', 8097, 27377), -- OptionBroadcastTextID: 2823 - 7509 - 8097
(13476, 10, 0, 'I can\'t find someone. Help!', 57727, 27377),
(13476, 9, 0, 'Where does Tina Mudclaw live?', 57723, 27377),
(13476, 8, 0, 'Where does Sho live?', 57720, 27377),
(13476, 7, 0, 'Where does Old Hillpaw live?', 57719, 27377),
(13476, 6, 0, 'Where does Jogu live?', 57726, 27377),
(13476, 5, 0, 'Where does Haohan Mudclaw live?', 57722, 27377),
(13476, 4, 0, 'Where does Gina Mudclaw live?', 57724, 27377),
(13476, 3, 0, 'Where does Fish Fellreed live?', 57738, 27377),
(13476, 2, 0, 'Where does Farmer Fung live?', 57725, 27377),
(13476, 1, 0, 'Where does Ella live?', 57718, 27377),
(13476, 0, 0, 'Where does Chee Chee live?', 57721, 27377),
(13445, 1, 0, 'What are you going to do, Farmer Yoon?', 64134, 27377),
(13641, 0, 0, 'He just inherited Sunsong Ranch. You can literally see him from where you are standing.', 59336, 27377),
(13642, 0, 0, 'I\'m here to pick up seeds for Farmer Yoon.', 59334, 27377),
(13584, 2, 5, 'Make this inn your home.', 2822, 27377),
(13583, 2, 1, 'Let me browse your goods.', 8097, 27377), -- OptionBroadcastTextID: 2823 - 7509 - 8097
(14379, 1, 1, 'I need supplies for cooking lessons.', 63983, 27377),
(14379, 0, 3, 'I seek training in Pandaren cooking.', 65287, 27377),
(14585, 0, 1, 'I need ingredients and equipment for my kitchen.', 65288, 27377),
(14422, 0, 3, 'I seek training in the Way of the Oven.', 65282, 27377),
(13608, 2, 3, 'I seek training in the Way of the Brew.', 65272, 27377),
(14581, 0, 3, 'I seek training in the Way of the Wok.', 65271, 27377),
(13609, 2, 3, 'I seek training in the Way of the Grill.', 65279, 27377),
(14584, 0, 3, 'I seek training in the Way of the Pot.', 65280, 27377),
(14583, 0, 3, 'I seek training in the Way of the Steamer.', 65281, 27377),
(15579, 20, 1, 'Do you happen to have any fishing supplies?', 72911, 27377),
(15579, 18, 3, 'I don\'t even know how to fish! Can you teach me?', 72910, 27377),
(15579, 11, 0, 'Even better, can you just show me on my map?', 72908, 27377),
(15579, 10, 0, 'Sure, I\'d love to hear a secret.', 72907, 27377);

INSERT INTO `gossip_menu_option` (`MenuId`, `OptionIndex`, `OptionIcon`, `OptionText`, `OptionBroadcastTextId`, `VerifiedBuild`) VALUES
(13343, 0, 3, 'I can instruct you in tailoring.  Interested?', 20133, 27377),
(13315, 0, 0, 'Go ahead and speak with the water, Ashyo.', 55764, 27377),
(13740, 0, 0, 'So, you\'re a homebrewer?', 60517, 27377),
(13279, 0, 0, 'What happened, Chen?', 55596, 27377),
(13750, 0, 0, 'Why aren\'t you helping me fight things?', 60556, 27377),
(13742, 0, 0, 'Ha ha.', 60521, 27377), -- OptionBroadcastTextID: 26582 - 60521
(13741, 0, 0, 'Is Mudmug your real name?', 60519, 27377),
(13270, 0, 0, 'I\'m ready. Let\'s hit the road.', 55319, 27377),
(14315, 1, 1, 'I would like to buy from you.', 14967, 27377), -- OptionBroadcastTextID: 2583 - 6399 - 7142 - 9992 - 14967
(14315, 0, 25, 'Queue for the Brewmoon Festival.', 64698, 27377),
(14330, 1, 1, 'I would like to buy from you.', 14967, 27377), -- OptionBroadcastTextID: 2583 - 6399 - 7142 - 9992 - 14967
(14330, 0, 5, 'Make this inn your home.', 2822, 27377),
(14934, 0, 0, 'Who are you?', 97339, 27377), -- OptionBroadcastTextID: 25092 - 38470 - 47091 - 47632 - 62792 - 65124 - 79414 - 97339
(13230, 11, 0, 'Hit me as hard as you possibly can!', 54815, 27377),
(13230, 10, 0, 'Hit me with average power!', 54813, 27377),
(13230, 9, 0, 'Hit me softly!', 54814, 27377),
(13230, 5, 0, 'Hit it as hard as possible.', 54811, 27377), -- OptionBroadcastTextID: 54805 - 54808 - 54811
(13230, 4, 0, 'Hit it with average power.', 54809, 27377), -- OptionBroadcastTextID: 54803 - 54806 - 54809
(13230, 3, 0, 'Hit it very softly.', 54810, 27377), -- OptionBroadcastTextID: 54804 - 54807 - 54810
(13230, 2, 0, 'Hit it as hard as possible.', 54811, 27377), -- OptionBroadcastTextID: 54805 - 54808 - 54811
(13230, 1, 0, 'Hit it with average power.', 54809, 27377), -- OptionBroadcastTextID: 54803 - 54806 - 54809
(13230, 0, 0, 'Hit it very softly.', 54810, 27377), -- OptionBroadcastTextID: 54804 - 54807 - 54810
(13230, 8, 0, 'Hit it as hard as possible.', 54811, 27377), -- OptionBroadcastTextID: 54805 - 54808 - 54811
(13230, 7, 0, 'Hit it with average power.', 54809, 27377), -- OptionBroadcastTextID: 54803 - 54806 - 54809
(13230, 6, 0, 'Hit it very softly.', 54810, 27377), -- OptionBroadcastTextID: 54804 - 54807 - 54810
(13237, 0, 0, 'Does all of this farmland belong to you?', 55077, 27377),
(12009, 0, 0, 'I\'ve come at your call, Stonemother.', 45522, 27326),
(11689, 1, 0, 'Throw me back up!', 45329, 27326),
(12243, 6, 0, 'Blasted Lands and the portal to Draenor', 129108, 27843),
(12243, 5, 0, 'Paw\'don Village in Pandaria', 129105, 27843),
(12243, 4, 0, 'Areas opened up in the Cataclysm', 129111, 27843), -- OptionBroadcastTextID: 129158 - 129111
(12243, 3, 0, 'Borean Tundra in Northrend', 129110, 27843), -- OptionBroadcastTextID: 129153 - 129110
(12243, 2, 0, 'Hellfire Peninsula in Outland', 129107, 27843), -- OptionBroadcastTextID: 129387 - 129365 - 129237 - 129226 - 129209 - 129176 - 129159 - 129107
(19861, 0, 0, 'Let\'s duel.', 114449, 27843),
(20486, 0, 0, 'I\'ve heard this tale before... <Skip the Legion introductory quests and begin your journey in Dalaran.>', 123132, 27843),
(19930, 1, 0, 'No, thank you.', 115299, 27843),
(19930, 0, 0, 'Sure, I\'ll take a sip.', 115298, 27843),
(18488, 1, 0, 'I hear you\'re an expert on naval equipment.  Have some time to help me out?', 98453, 27602),
(18486, 7, 28, 'I would like to build another destroyer.', 98351, 27602),
(18486, 6, 28, 'Start construction on our first destroyer.', 95538, 27602),
(18337, 2, 0, 'Fel corrupted water is just pouring down from the mountain. What is going on at the Throne of Kil\'jaeden?', 94832, 27602),
(18337, 1, 0, 'The Fel Forge looks completely corrupted, what are they building there?', 94830, 27602),
(18337, 0, 0, 'Lots of ships coming into that harbor, what\'s going on there?', 94085, 27602),
(18226, 0, 0, 'What happened here?', 107100, 27602), -- OptionBroadcastTextID: 38328 - 90273 - 92991 - 105842 - 107100
(18328, 0, 0, 'What\'s the situation?', 92972, 27602), -- OptionBroadcastTextID: 69705 - 85723 - 92972
(18253, 2, 0, 'Take me to the Iron Front.', 92950, 27602),
(18582, 4, 0, 'The Mechashredder.', 96771, 27602),
(18582, 2, 0, 'Artillery Strike.', 96769, 27602),
(18582, 0, 0, 'Call to Arms.', 96767, 27602),
(16242, 0, 0, 'I\'m ready, Fiona.', 79206, 27547),
(16663, 2, 0, 'Brighteye, go fetch!', 84053, 27547),
(16663, 1, 0, 'Okay, Brighteye, now play dead!', 84056, 27547),
(16663, 0, 0, 'Sit, Brighteye, sit!', 84055, 27547),
(17533, 0, 0, 'I need you to come on patrol with me.', 81638, 27547),
(16940, 1, 0, 'What are you doing here?', 123345, 27547), -- OptionBroadcastTextID: 35775 - 38471 - 57803 - 57891 - 66486 - 81341 - 86824 - 123345
(16424, 0, 0, 'Prophet, we\'re being overrun!', 81697, 27547),
(15997, 0, 0, 'Let\'s get out of here!', 106187, 27547), -- OptionBroadcastTextID: 21971 - 77067 - 97823 - 106187
(16442, 2, 0, 'Your allies\' lives will mean nothing if you give up here. Let their sacrifice inspire you.', 81927, 27547),
(16442, 1, 0, 'It is not our deaths that matter in the end, but how we live. How will you live, Yrel?', 81926, 27547),
(16442, 0, 0, 'You cannot abandon them to this fate. If we forsake our friends now, we are no better than Ner\'zhul.', 81925, 27547),
(15997, 3, 0, 'Think of your people. The captives still need our help!', 81487, 27547),
(15997, 2, 0, 'Believe in the Light! Despite setbacks, it will always prevail.', 81497, 27547),
(15997, 1, 0, 'We can\'t give up now! Heroes learn from their mistakes.', 81489, 27547),
(16395, 8, 0, 'Pull yourself together, Yrel! You can do better than this!', 81493, 27547),
(16395, 3, 0, 'We all start from humble beginnings. I took my first steps outside an abbey in Elwynn Forest.', 81916, 27547),
(16395, 0, 0, 'You must choose, Yrel. Will you rise and fight, or fall here to doubt?', 81495, 27547),
(16396, 2, 0, 'Your people have triumphed over endless persecution. Will you let their hopes die here without a fight?', 81501, 27547),
(16396, 1, 0, '\'Doubt the Light\' just doesn\'t have the same ring to it.', 81500, 27547),
(16396, 0, 0, 'The Light is only as strong as its champions. Believe in YOURSELF.', 81499, 27547),
(15860, 0, 0, 'I need a Shadowmoon orc illusion.', 81975, 27547),
(16454, 1, 1, 'I would like to buy from you.', 14967, 27547), -- OptionBroadcastTextID: 2583 - 6399 - 7142 - 9992 - 14967
(16454, 0, 5, 'Make this inn your home.', 2822, 27547),
(15174, 3, 1, 'Can I purchase one of your traps?', 68924, 27377),
(15212, 0, 1, 'I would like to buy from you.', 14967, 27377), -- OptionBroadcastTextID: 2583 - 6399 - 7142 - 9992 - 14967
(14955, 1, 0, 'I\'m ready to leave.', 60252, 27377),
(16509, 13, 0, 'Tell me of the Downfall of Garrosh Hellscream.', 82880, 27377),
(16509, 12, 0, 'Tell me of the Underhold beneath Orgrimmar.', 82879, 27377),
(16509, 11, 0, 'Tell me of the war that came to the Gates of Retribution.', 82878, 27377),
(16509, 10, 0, 'Tell me of the Vale of Eternal Sorrows that surrounds us.', 82877, 27377),
(16509, 9, 0, 'Tell me of Lei Shen\'s Pinnacle of Storms.', 82876, 27377),
(16509, 8, 0, 'Tell me of the twisted mogu Halls of Flesh-Shaping.', 82875, 27377),
(16509, 7, 0, 'Tell me of the Forgotten Depths beneath the Throne of Thunder.', 82874, 27377),
(16509, 6, 0, 'Tell me of the Last Stand of the Zandalari.', 82873, 27377),
(16509, 5, 0, 'Tell me of the Terrace of Endless Spring.', 82871, 27377),
(16509, 4, 0, 'Tell me of the Nightmare of Shek\'zeer.', 82870, 27377),
(16509, 3, 0, 'Tell me of the Dread Approach to the Heart of Fear.', 82869, 27377),
(16509, 2, 0, 'Tell me of the Vault of Mysteries.', 82868, 27377),
(16509, 1, 0, 'Tell me of the Guardians of Mogu\'shan.', 82865, 27377),
(16370, 6, 0, 'Tell me of the Crypt of Forgotten Kings (Heroic).', 81201, 27377),
(16370, 5, 0, 'Tell me the tale of a Brewing Storm (Heroic).', 81200, 27377),
(16370, 4, 0, 'Tell me the tale of Blood in the Snow (Heroic).', 81199, 27377),
(16370, 3, 0, 'Tell me of the Secrets of Ragefire (Heroic).', 81198, 27377),
(16370, 2, 0, 'Tell me of the unearthing of the Dark Heart of Pandaria (Heroic).', 81197, 27377),
(16370, 1, 0, 'Tell me of the Battle on the High Seas (Heroic).', 81196, 27377),
(16364, 16, 0, 'Tell me the tale of Blood in the Snow.', 81154, 27377),
(16364, 15, 0, 'Tell me of the Secrets of Ragefire.', 81153, 27377),
(16364, 14, 0, 'Tell me of the unearthing of the Dark Heart of Pandaria.', 81152, 27377),
(16364, 13, 0, 'Tell me of the Battle on the High Seas.', 81150, 27377),
(16364, 12, 0, 'Tell me of the defense of Lion\'s Landing.', 83422, 27377),
(16364, 10, 0, 'Tell me of how Varian and Tyrande learned a Little Patience.', 81151, 27377),
(16364, 9, 0, 'Tell me of the Dagger in the Dark that felled Vol\'jin.', 81149, 27377),
(16364, 8, 0, 'Tell me of the Assault on Zan\'vess.', 81146, 27377),
(16364, 7, 0, 'Tell me of Theramore\'s Fall.', 81148, 27377),
(16364, 6, 0, 'Tell me of the Brewmoon Festival.', 81147, 27377),
(16364, 5, 0, 'Tell me the tale of a Brewing Storm.', 81145, 27377),
(16364, 4, 0, 'Tell me of the Arena of Annihilation.', 81144, 27377),
(16364, 3, 0, 'Tell me of the Crypt of Forgotten Kings.', 81143, 27377),
(16364, 2, 0, 'Tell me of Unga Ingoo.', 81142, 27377),
(16364, 1, 0, 'Tell me of Greenstone Village.', 81141, 27377),
(14615, 1, 1, 'Let me in on your other projects.', 65828, 27377),
(14615, 0, 3, 'I need some training.', 65826, 27377),
(14582, 0, 3, 'Train me in Inscription.', 88801, 27377), -- OptionBroadcastTextID: 47113 - 88801
(15152, 11, 0, 'Other', 66646, 27377),
(15152, 10, 0, 'Vendor', 44612, 27377),
(15152, 9, 0, 'Stable Master', 45383, 27377), -- OptionBroadcastTextID: 8508 - 8511 - 8518 - 8524 - 8525 - 8529 - 8534 - 8536 - 8539 - 8542 - 15228 - 19208 - 45383
(15152, 8, 0, 'Transmogrification and Void Storage', 72967, 27377),
(15152, 7, 0, 'Quartermasters', 66700, 27377),
(15152, 6, 0, 'Profession Trainer', 45382, 27377), -- OptionBroadcastTextID: 2869 - 3430 - 4896 - 5112 - 5352 - 5916 - 6635 - 6912 - 7022 - 7095 - 15250 - 19210 - 45382
(15152, 5, 0, 'Pet Battle Trainer', 66645, 27377),
(15152, 4, 0, 'Inn', 44629, 27377), -- OptionBroadcastTextID: 5513 - 5911 - 6396 - 6633 - 6910 - 15224 - 19202 - 32166 - 44629
(15152, 3, 0, 'Flying Trainer', 66644, 27377),
(15152, 2, 0, 'Flight Master', 45379, 27377), -- OptionBroadcastTextID: 2863 - 4889 - 6632 - 19203 - 45379
(15152, 1, 0, 'Bank', 78584, 27377), -- OptionBroadcastTextID: 3426 - 5908 - 6631 - 6907 - 6987 - 15214 - 19201 - 32167 - 44628 - 78584
(14404, 0, 0, 'Can you play me a song?', 64617, 27377),
(14558, 11, 0, 'Other', 66646, 27377),
(14558, 10, 0, 'Vendor', 44612, 27377),
(14558, 9, 0, 'Stable Master', 45383, 27377), -- OptionBroadcastTextID: 8508 - 8511 - 8518 - 8524 - 8525 - 8529 - 8534 - 8536 - 8539 - 8542 - 15228 - 19208 - 45383
(14558, 7, 0, 'Quartermasters', 66700, 27377),
(14558, 6, 0, 'Profession Trainer', 45382, 27377), -- OptionBroadcastTextID: 2869 - 3430 - 4896 - 5112 - 5352 - 5916 - 6635 - 6912 - 7022 - 7095 - 15250 - 19210 - 45382
(14558, 5, 0, 'Pet Battle Trainer', 66645, 27377),
(14558, 4, 0, 'Inn', 44629, 27377), -- OptionBroadcastTextID: 5513 - 5911 - 6396 - 6633 - 6910 - 15224 - 19202 - 32166 - 44629
(14558, 3, 0, 'Flying Trainer', 66644, 27377),
(14558, 2, 0, 'Flight Master', 45379, 27377), -- OptionBroadcastTextID: 2863 - 4889 - 6632 - 19203 - 45379
(14558, 1, 0, 'Bank', 78584, 27377), -- OptionBroadcastTextID: 3426 - 5908 - 6631 - 6907 - 6987 - 15214 - 19201 - 32167 - 44628 - 78584
(15718, 0, 1, 'I would like to buy from you.', 14967, 27377), -- OptionBroadcastTextID: 2583 - 6399 - 7142 - 9992 - 14967
(15952, 0, 1, 'Examine his goods.', 76560, 27377),
(14680, 2, 0, 'What can I find here in the city?', 66598, 27377),
(14680, 0, 5, 'Make this inn your home.', 2822, 27377),
(14806, 0, 0, 'He knows more about this land than we do. Perhaps you should heed his warnings.', 66784, 27377),
(14833, 11, 0, 'Other', 66646, 27377),
(14833, 10, 0, 'Vendor', 44612, 27377),
(14833, 9, 0, 'Stable Master', 45383, 27377), -- OptionBroadcastTextID: 8508 - 8511 - 8518 - 8524 - 8525 - 8529 - 8534 - 8536 - 8539 - 8542 - 15228 - 19208 - 45383
(14833, 7, 0, 'Quartermasters', 66700, 27377),
(14833, 6, 0, 'Profession Trainer', 45382, 27377), -- OptionBroadcastTextID: 2869 - 3430 - 4896 - 5112 - 5352 - 5916 - 6635 - 6912 - 7022 - 7095 - 15250 - 19210 - 45382
(14833, 5, 0, 'Pet Battle Trainer', 66645, 27377),
(14833, 4, 0, 'Inn', 44629, 27377), -- OptionBroadcastTextID: 5513 - 5911 - 6396 - 6633 - 6910 - 15224 - 19202 - 32166 - 44629
(14833, 3, 0, 'Flying Trainer', 66644, 27377),
(14833, 2, 0, 'Flight Master', 45379, 27377), -- OptionBroadcastTextID: 2863 - 4889 - 6632 - 19203 - 45379
(14833, 1, 0, 'Bank', 78584, 27377), -- OptionBroadcastTextID: 3426 - 5908 - 6631 - 6907 - 6987 - 15214 - 19201 - 32167 - 44628 - 78584
(14690, 0, 0, 'I have another question.', 98552, 27377), -- OptionBroadcastTextID: 12241 - 12478 - 23442 - 62310 - 98552
(15690, 0, 0, 'I\'d like to travel to Ratchet.', 73922, 27377),
(15107, 0, 0, 'How do I become a battle pet trainer?', 68459, 27377),
(14518, 0, 0, 'Where can I find the Shado-Pan Quartermaster?', 66722, 27377),
(14346, 1, 0, 'Why should I help the Shado-Pan?', 64751, 27377),
(14346, 0, 0, 'How can I help the Shado-Pan?', 64752, 27377),
(14523, 0, 0, 'Where can I find the Klaxxi Quartermaster?', 66719, 27377),
(14522, 1, 0, 'How will I be rewarded by helping the Klaxxi?', 64761, 27377),
(14522, 0, 0, 'How can I help the Klaxxi?', 64762, 27377),
(13651, 2, 1, 'I would like to buy from you.', 14967, 27377), -- OptionBroadcastTextID: 2583 - 6399 - 7142 - 9992 - 14967
(14514, 0, 0, 'Where can I find the Golden Lotus Quartermaster?', 66718, 27377),
(14347, 1, 0, 'Will I be rewarded for helping to defend the Vale?', 64745, 27377),
(14347, 0, 0, 'How can I help The Golden Lotus?', 64746, 27377),
(14348, 3, 1, 'I would like to buy from you.', 14967, 27377), -- OptionBroadcastTextID: 2583 - 6399 - 7142 - 9992 - 14967
(14348, 2, 0, 'Why should I help the August Celestials?', 64740, 27377),
(14348, 1, 0, 'How can I help the August Celestials today?', 64741, 27377),
(14512, 0, 1, 'I would like to buy from you.', 14967, 27377), -- OptionBroadcastTextID: 2583 - 6399 - 7142 - 9992 - 14967
(14513, 0, 1, 'I would like to buy from you.', 14967, 27377), -- OptionBroadcastTextID: 2583 - 6399 - 7142 - 9992 - 14967
(14510, 0, 0, 'What is this place?', 136659, 27377), -- OptionBroadcastTextID: 18411 - 39050 - 53647 - 60157 - 66591 - 94147 - 136659
(14508, 0, 0, 'Where can I find the Order of the Cloud Serpent Quartermaster?', 66721, 27377),
(14507, 1, 0, 'What is the reward for rising through the Order of the Cloud Serpent?', 64730, 27377),
(14507, 0, 0, 'What does it mean to join the Order of the Cloud Serpent?', 64729, 27377),
(14504, 0, 1, 'I would like to buy from you.', 14967, 27377), -- OptionBroadcastTextID: 2583 - 6399 - 7142 - 9992 - 14967
(14505, 0, 0, 'Where can I find the Tillers Quartermaster?', 66723, 27377),
(14350, 1, 0, 'Why should I help the Tillers?', 64724, 27377),
(14350, 0, 0, 'What kind of stuff can I do with the Tillers?', 64725, 27377),
(14503, 0, 0, 'Where can I find the Anglers Quartermaster?', 66716, 27377),
(14349, 1, 0, 'If I help the Anglers, what\'s in it for me?', 64716, 27377),
(14349, 0, 0, 'Where can I find the Anglers?', 64717, 27377),
(14351, 1, 0, 'Are there rewards for helping brewmasters?', 64693, 27377),
(14351, 0, 0, 'Where can I find brewmasters that might need aid?', 64694, 27377),
(14520, 0, 0, 'Where can I find the Lorewalkers Quartermaster?', 66720, 27377),
(14519, 1, 0, 'Why should I help the Lorewalkers?', 64756, 27377),
(14519, 0, 0, 'How can I help the Lorewalkers?', 64757, 27377),
(14575, 0, 1, 'I would like to buy from you.', 14967, 27377), -- OptionBroadcastTextID: 2583 - 6399 - 7142 - 9992 - 14967
(14692, 2, 0, 'I have another question.', 98552, 27377), -- OptionBroadcastTextID: 12241 - 12478 - 23442 - 62310 - 98552
(14692, 1, 0, 'Class Trainer', 45378, 27377), -- OptionBroadcastTextID: 2868 - 3429 - 4891 - 5088 - 5360 - 5915 - 6634 - 6911 - 6999 - 7078 - 15234 - 32202 - 45378
(14692, 0, 0, 'Battlemasters', 45377, 27377), -- OptionBroadcastTextID: 15232 - 32197 - 45377
(14751, 0, 0, 'I have another question.', 98552, 27377), -- OptionBroadcastTextID: 12241 - 12478 - 23442 - 62310 - 98552
(14752, 0, 0, 'I have another question.', 98552, 27377), -- OptionBroadcastTextID: 12241 - 12478 - 23442 - 62310 - 98552
(14693, 22, 0, 'I have another question.', 98552, 27377), -- OptionBroadcastTextID: 12241 - 12478 - 23442 - 62310 - 98552
(14693, 21, 0, 'Trade Supplies', 45445, 27377), -- OptionBroadcastTextID: 32719 - 45445
(14693, 20, 0, 'Tailoring Supplies', 66673, 27377),
(14693, 19, 0, 'Sweet Treats', 66672, 27377),
(14693, 18, 0, 'Poisons & Reagents', 45446, 27377),
(14693, 17, 0, 'Mining Supplies', 66671, 27377),
(14693, 16, 0, 'Meat', 66670, 27377),
(14693, 15, 0, 'Leatherworking & Skinning Supplies', 66669, 27377),
(14693, 14, 0, 'Jewelcrafting Supplies', 66668, 27377),
(14693, 13, 0, 'Inscription Supplies', 66667, 27377),
(14693, 12, 0, 'Herbs', 66665, 27377),
(14693, 11, 0, 'General Goods', 45444, 27377), -- OptionBroadcastTextID: 32712 - 45444
(14693, 10, 0, 'Food & Drink', 66664, 27377), -- OptionBroadcastTextID: 23755 - 23962 - 66664
(14693, 9, 0, 'Fishing Supplies', 66663, 27377),
(14693, 8, 0, 'First Aid Supplies', 66662, 27377),
(14693, 7, 0, 'Fireworks', 66661, 27377),
(14693, 6, 0, 'Engineering Supplies', 66659, 27377),
(14693, 5, 0, 'Enchanting Supplies', 66658, 27377),
(14693, 4, 0, 'Cooking Supplies', 66657, 27377),
(14693, 3, 0, 'Brews', 66656, 27377),
(14693, 2, 0, 'Bread', 66655, 27377),
(14693, 1, 0, 'Blacksmithing Supplies', 66654, 27377),
(14693, 0, 0, 'Alchemy Goods', 66653, 27377),
(14771, 0, 0, 'I have another question.', 98552, 27377), -- OptionBroadcastTextID: 12241 - 12478 - 23442 - 62310 - 98552
(14750, 0, 0, 'I have another question.', 98552, 27377), -- OptionBroadcastTextID: 12241 - 12478 - 23442 - 62310 - 98552
(14749, 0, 0, 'I have another question.', 98552, 27377), -- OptionBroadcastTextID: 12241 - 12478 - 23442 - 62310 - 98552
(14748, 0, 0, 'I have another question.', 98552, 27377), -- OptionBroadcastTextID: 12241 - 12478 - 23442 - 62310 - 98552
(14747, 0, 0, 'I have another question.', 98552, 27377), -- OptionBroadcastTextID: 12241 - 12478 - 23442 - 62310 - 98552
(14746, 0, 0, 'I have another question.', 98552, 27377), -- OptionBroadcastTextID: 12241 - 12478 - 23442 - 62310 - 98552
(14745, 0, 0, 'I have another question.', 98552, 27377), -- OptionBroadcastTextID: 12241 - 12478 - 23442 - 62310 - 98552
(14744, 0, 0, 'I have another question.', 98552, 27377), -- OptionBroadcastTextID: 12241 - 12478 - 23442 - 62310 - 98552
(14743, 0, 0, 'I have another question.', 98552, 27377), -- OptionBroadcastTextID: 12241 - 12478 - 23442 - 62310 - 98552
(14742, 0, 0, 'I have another question.', 98552, 27377), -- OptionBroadcastTextID: 12241 - 12478 - 23442 - 62310 - 98552
(14770, 0, 0, 'I have another question.', 98552, 27377), -- OptionBroadcastTextID: 12241 - 12478 - 23442 - 62310 - 98552
(14741, 0, 0, 'I have another question.', 98552, 27377), -- OptionBroadcastTextID: 12241 - 12478 - 23442 - 62310 - 98552
(14740, 0, 0, 'I have another question.', 98552, 27377), -- OptionBroadcastTextID: 12241 - 12478 - 23442 - 62310 - 98552
(14739, 0, 0, 'I have another question.', 98552, 27377), -- OptionBroadcastTextID: 12241 - 12478 - 23442 - 62310 - 98552
(14738, 0, 0, 'I have another question.', 98552, 27377), -- OptionBroadcastTextID: 12241 - 12478 - 23442 - 62310 - 98552
(14737, 0, 0, 'I have another question.', 98552, 27377), -- OptionBroadcastTextID: 12241 - 12478 - 23442 - 62310 - 98552
(14736, 0, 0, 'I have another question.', 98552, 27377), -- OptionBroadcastTextID: 12241 - 12478 - 23442 - 62310 - 98552
(14735, 0, 0, 'I have another question.', 98552, 27377), -- OptionBroadcastTextID: 12241 - 12478 - 23442 - 62310 - 98552
(14697, 0, 0, 'I have another question.', 98552, 27377), -- OptionBroadcastTextID: 12241 - 12478 - 23442 - 62310 - 98552
(14696, 0, 0, 'I have another question.', 98552, 27377), -- OptionBroadcastTextID: 12241 - 12478 - 23442 - 62310 - 98552
(14695, 0, 0, 'I have another question.', 98552, 27377), -- OptionBroadcastTextID: 12241 - 12478 - 23442 - 62310 - 98552
(14694, 0, 0, 'I have another question.', 98552, 27377), -- OptionBroadcastTextID: 12241 - 12478 - 23442 - 62310 - 98552
(14691, 0, 0, 'I have another question.', 98552, 27377), -- OptionBroadcastTextID: 12241 - 12478 - 23442 - 62310 - 98552
(14772, 13, 0, 'I have another question.', 98552, 27377), -- OptionBroadcastTextID: 12241 - 12478 - 23442 - 62310 - 98552
(14772, 12, 0, 'Tillers', 66706, 27377),
(14772, 11, 0, 'Shado-Pan', 66709, 27377),
(14772, 10, 0, 'Order of the Cloud Serpent', 66707, 27377),
(14772, 9, 0, 'Lorewalkers', 66713, 27377),
(14772, 8, 0, 'Klaxxi', 66708, 27377),
(14772, 7, 0, 'Golden Lotus', 66710, 27377),
(14772, 5, 0, 'August Celestials', 66712, 27377),
(14772, 4, 0, 'Anglers', 66704, 27377),
(14772, 3, 0, 'Valor Quartermaster', 66702, 27377),
(14772, 2, 0, 'Justice Quartermaster', 66945, 27377),
(14772, 1, 0, 'Honor Quartermaster', 66703, 27377),
(14772, 0, 0, 'Conquest Quartermaster', 66701, 27377),
(14785, 0, 0, 'I have another question.', 98552, 27377), -- OptionBroadcastTextID: 12241 - 12478 - 23442 - 62310 - 98552
(14784, 0, 0, 'I have another question.', 98552, 27377); -- OptionBroadcastTextID: 12241 - 12478 - 23442 - 62310 - 98552

INSERT INTO `gossip_menu_option` (`MenuId`, `OptionIndex`, `OptionIcon`, `OptionText`, `OptionBroadcastTextId`, `VerifiedBuild`) VALUES
(14783, 0, 0, 'I have another question.', 98552, 27377), -- OptionBroadcastTextID: 12241 - 12478 - 23442 - 62310 - 98552
(14782, 0, 0, 'I have another question.', 98552, 27377), -- OptionBroadcastTextID: 12241 - 12478 - 23442 - 62310 - 98552
(14781, 0, 0, 'I have another question.', 98552, 27377), -- OptionBroadcastTextID: 12241 - 12478 - 23442 - 62310 - 98552
(14780, 0, 0, 'I have another question.', 98552, 27377), -- OptionBroadcastTextID: 12241 - 12478 - 23442 - 62310 - 98552
(14778, 0, 0, 'I have another question.', 98552, 27377), -- OptionBroadcastTextID: 12241 - 12478 - 23442 - 62310 - 98552
(14776, 0, 0, 'I have another question.', 98552, 27377), -- OptionBroadcastTextID: 12241 - 12478 - 23442 - 62310 - 98552
(14775, 0, 0, 'I have another question.', 98552, 27377), -- OptionBroadcastTextID: 12241 - 12478 - 23442 - 62310 - 98552
(14831, 0, 0, 'I have another question.', 98552, 27377), -- OptionBroadcastTextID: 12241 - 12478 - 23442 - 62310 - 98552
(14774, 0, 0, 'I have another question.', 98552, 27377), -- OptionBroadcastTextID: 12241 - 12478 - 23442 - 62310 - 98552
(14773, 0, 0, 'I have another question.', 98552, 27377), -- OptionBroadcastTextID: 12241 - 12478 - 23442 - 62310 - 98552
(14769, 15, 0, 'I have another question.', 98552, 27377), -- OptionBroadcastTextID: 12241 - 12478 - 23442 - 62310 - 98552
(14769, 14, 0, 'Tailoring', 52077, 27377), -- OptionBroadcastTextID: 2951 - 3469 - 4871 - 5144 - 5380 - 5900 - 6629 - 6717 - 6787 - 6956 - 7035 - 7121 - 15275 - 32148 - 45760 - 52077
(14769, 13, 0, 'Skinning', 106243, 27377), -- OptionBroadcastTextID: 2948 - 3471 - 4869 - 5140 - 5376 - 5899 - 6628 - 6716 - 6786 - 6955 - 7034 - 7118 - 15273 - 19237 - 45770 - 52076 - 106243
(14769, 12, 0, 'Mining', 78976, 27377), -- OptionBroadcastTextID: 2944 - 3468 - 4868 - 5138 - 5898 - 6627 - 6714 - 6785 - 6954 - 7033 - 15271 - 32147 - 45769 - 51348 - 78976
(14769, 11, 0, 'Leatherworking', 52071, 27377), -- OptionBroadcastTextID: 2947 - 3467 - 4866 - 5133 - 5371 - 5897 - 6626 - 6713 - 6784 - 6953 - 7032 - 7115 - 15269 - 19236 - 45759 - 52071
(14769, 10, 0, 'Jewelcrafting', 45758, 27377), -- OptionBroadcastTextID: 15267 - 18338 - 19235 - 44647 - 45758
(14769, 9, 0, 'Inscription', 48811, 27377), -- OptionBroadcastTextID: 31542 - 32146 - 45757 - 48811
(14769, 8, 0, 'Herbalism', 45768, 27377), -- OptionBroadcastTextID: 2950 - 3466 - 4865 - 5129 - 5130 - 5370 - 5896 - 6625 - 6712 - 6783 - 6952 - 7031 - 7112 - 15265 - 32145 - 45434 - 45768
(14769, 7, 0, 'Fishing', 99684, 27377), -- OptionBroadcastTextID: 3005 - 3465 - 4864 - 5127 - 5368 - 5895 - 6624 - 6711 - 6782 - 6951 - 7030 - 7109 - 15263 - 32144 - 45436 - 45767 - 99684
(14769, 6, 0, 'First Aid', 52066, 27377), -- OptionBroadcastTextID: 2949 - 3464 - 4863 - 5125 - 5366 - 5894 - 6623 - 6710 - 6781 - 6950 - 7029 - 7106 - 15261 - 19238 - 45765 - 52066
(14769, 5, 0, 'Engineering', 51347, 27377), -- OptionBroadcastTextID: 2943 - 4976 - 5123 - 5893 - 6622 - 6780 - 6949 - 7028 - 15259 - 32143 - 45756 - 51347
(14769, 4, 0, 'Enchanting', 52063, 27377), -- OptionBroadcastTextID: 3006 - 3463 - 4862 - 5121 - 5363 - 5892 - 6621 - 6709 - 6779 - 6948 - 7027 - 7103 - 15257 - 19234 - 45755 - 52063
(14769, 3, 0, 'Cooking', 45763, 27377), -- OptionBroadcastTextID: 2945 - 3462 - 4861 - 5119 - 5356 - 5891 - 6620 - 6708 - 6778 - 6947 - 7026 - 7100 - 16029 - 19233 - 45432 - 45763
(14769, 2, 0, 'Blacksmithing', 51346, 27377), -- OptionBroadcastTextID: 2942 - 3461 - 4860 - 5117 - 5890 - 6619 - 6707 - 6777 - 6946 - 7025 - 15255 - 19249 - 45754 - 51346
(14769, 1, 0, 'Archaeology', 44649, 27377),
(14769, 0, 0, 'Alchemy', 52058, 27377), -- OptionBroadcastTextID: 2952 - 3460 - 4859 - 5114 - 5354 - 5362 - 5889 - 6618 - 6706 - 6776 - 6945 - 7024 - 7097 - 15252 - 19232 - 45753 - 52058
(14768, 0, 0, 'I have another question.', 98552, 27377), -- OptionBroadcastTextID: 12241 - 12478 - 23442 - 62310 - 98552
(14767, 0, 0, 'I have another question.', 98552, 27377), -- OptionBroadcastTextID: 12241 - 12478 - 23442 - 62310 - 98552
(14766, 0, 0, 'I have another question.', 98552, 27377), -- OptionBroadcastTextID: 12241 - 12478 - 23442 - 62310 - 98552
(14765, 0, 0, 'I have another question.', 98552, 27377), -- OptionBroadcastTextID: 12241 - 12478 - 23442 - 62310 - 98552
(14764, 0, 0, 'I have another question.', 98552, 27377), -- OptionBroadcastTextID: 12241 - 12478 - 23442 - 62310 - 98552
(14763, 0, 0, 'I have another question.', 98552, 27377), -- OptionBroadcastTextID: 12241 - 12478 - 23442 - 62310 - 98552
(14761, 0, 0, 'I have another question.', 98552, 27377), -- OptionBroadcastTextID: 12241 - 12478 - 23442 - 62310 - 98552
(14762, 0, 0, 'I have another question.', 98552, 27377), -- OptionBroadcastTextID: 12241 - 12478 - 23442 - 62310 - 98552
(14754, 0, 0, 'I have another question.', 98552, 27377), -- OptionBroadcastTextID: 12241 - 12478 - 23442 - 62310 - 98552
(14760, 0, 0, 'I have another question.', 98552, 27377), -- OptionBroadcastTextID: 12241 - 12478 - 23442 - 62310 - 98552
(14759, 0, 0, 'I have another question.', 98552, 27377), -- OptionBroadcastTextID: 12241 - 12478 - 23442 - 62310 - 98552
(14758, 0, 0, 'I have another question.', 98552, 27377), -- OptionBroadcastTextID: 12241 - 12478 - 23442 - 62310 - 98552
(14756, 0, 0, 'I have another question.', 98552, 27377), -- OptionBroadcastTextID: 12241 - 12478 - 23442 - 62310 - 98552
(14757, 0, 0, 'I have another question.', 98552, 27377), -- OptionBroadcastTextID: 12241 - 12478 - 23442 - 62310 - 98552
(14755, 0, 0, 'I have another question.', 98552, 27377), -- OptionBroadcastTextID: 12241 - 12478 - 23442 - 62310 - 98552
(14689, 0, 0, 'I have another question.', 98552, 27377), -- OptionBroadcastTextID: 12241 - 12478 - 23442 - 62310 - 98552
(14688, 0, 0, 'I have another question.', 98552, 27377), -- OptionBroadcastTextID: 12241 - 12478 - 23442 - 62310 - 98552
(14686, 0, 0, 'I have another question.', 98552, 27377), -- OptionBroadcastTextID: 12241 - 12478 - 23442 - 62310 - 98552
(14561, 0, 0, 'I have another question.', 98552, 27377), -- OptionBroadcastTextID: 12241 - 12478 - 23442 - 62310 - 98552
(15127, 2, 0, 'I\'d like to heal and revive my battle pets.', 64115, 27377),
(14630, 0, 3, 'Train me in Blacksmithing.', 47110, 27377),
(14470, 0, 1, 'Let me browse your goods.', 8097, 27377), -- OptionBroadcastTextID: 2823 - 7509 - 8097
(13637, 0, 1, 'I would like to buy from you.', 14967, 27377), -- OptionBroadcastTextID: 2583 - 6399 - 7142 - 9992 - 14967
(13635, 1, 1, 'I would like to buy from you.', 14967, 27377), -- OptionBroadcastTextID: 2583 - 6399 - 7142 - 9992 - 14967
(13635, 0, 5, 'Make this inn your home.', 2822, 27377),
(13691, 0, 0, 'Well you can\'t just stay in here! You leave me no choice!\n<Use the Fire Lotus Incense.>', 0, 27377),
(13692, 0, 0, 'Are you sure you don\'t want to come with me?', 59849, 27377),
(13636, 0, 1, 'I would like to buy from you.', 14967, 27377), -- OptionBroadcastTextID: 2583 - 6399 - 7142 - 9992 - 14967
(13644, 0, 1, 'I would like to buy from you.', 14967, 27377), -- OptionBroadcastTextID: 2583 - 6399 - 7142 - 9992 - 14967
(13591, 0, 1, 'I would like to buy from you.', 14967, 27377), -- OptionBroadcastTextID: 2583 - 6399 - 7142 - 9992 - 14967
(13554, 0, 1, 'Show me your wares.', 90189, 27377), -- OptionBroadcastTextID: 58437 - 90189
(13671, 1, 0, 'What is a grummle?', 61782, 27377),
(13671, 0, 0, 'What is a \"luckydo\"?', 61779, 27377),
(13852, 0, 0, 'I want to ask something else.', 121489, 27377), -- OptionBroadcastTextID: 61781 - 121489
(13851, 0, 0, 'I want to ask something else.', 121489, 27377), -- OptionBroadcastTextID: 61781 - 121489
(15540, 0, 1, 'I\'ll... take a look.', 16317, 27377),
(14528, 0, 1, 'I would like to buy from you.', 14967, 27377), -- OptionBroadcastTextID: 2583 - 6399 - 7142 - 9992 - 14967
(13789, 0, 1, 'I would like to buy from you.', 14967, 27377), -- OptionBroadcastTextID: 2583 - 6399 - 7142 - 9992 - 14967
(14868, 0, 0, 'I\'m from the Alliance. We\'re here to save you and rebuild your village.', 67011, 27377), -- OptionBroadcastTextID: 67009 - 67011
(14855, 0, 0, 'I\'m from the Alliance. We\'re here to save you and rebuild your village.', 67011, 27377), -- OptionBroadcastTextID: 67009 - 67011
(13783, 0, 0, 'I\'m ready. Begin the ritual.', 61092, 27377),
(13803, 0, 0, 'There\'s still hope - Gorai is still alive, to the south. Go!', 61045, 27377),
(14800, 0, 3, 'Train me in First Aid.', 66761, 27377),
(14530, 0, 0, 'Who is in the Vale now?', 64795, 27377),
(14532, 0, 0, 'What is the Vale of Eternal Blossoms?', 64777, 27377),
(13580, 1, 1, 'I would like to buy from you.', 14967, 27366), -- OptionBroadcastTextID: 2583 - 6399 - 7142 - 9992 - 14967
(13580, 0, 25, 'Queue for A Brewing Storm.', 64696, 27366),
(13044, 0, 0, 'Get to Hanae\'s house. It\'s safe there.', 53135, 27366),
(13646, 0, 0, 'I am ready to leave.', 59390, 27366), -- OptionBroadcastTextID: 58399 - 59390
(14381, 0, 0, 'Let\'s do this, Mishi!', 63998, 27366),
(14364, 0, 0, 'I am ready to leave.', 59390, 27366), -- OptionBroadcastTextID: 58399 - 59390
(13592, 0, 0, 'What can I do to help?', 83851, 27366), -- OptionBroadcastTextID: 45678 - 58813 - 83851
(13605, 1, 3, 'What can you teach me?', 9980, 27366),
(13605, 0, 0, 'What can I do to help?', 83851, 27366), -- OptionBroadcastTextID: 45678 - 58813 - 83851
(13581, 0, 0, 'Let\'s see what you\'ve got.', 58725, 27366), -- OptionBroadcastTextID: 17041 - 58725
(13228, 0, 0, 'What can I do to help?', 83851, 27366), -- OptionBroadcastTextID: 45678 - 58813 - 83851
(13281, 0, 1, 'Let me browse your goods.', 8097, 27366), -- OptionBroadcastTextID: 2823 - 7509 - 8097
(13325, 0, 0, 'I would like to return to the temple grounds.', 56094, 27366),
(13324, 1, 0, 'I have a message for the Jade Serpent.', 56092, 27366),
(13372, 0, 1, 'I would like to buy from you.', 14967, 27366), -- OptionBroadcastTextID: 2583 - 6399 - 7142 - 9992 - 14967
(13371, 0, 5, 'Make this inn your home.', 2822, 27366),
(13550, 2, 0, 'Take me to the Temple of the Jade Serpent.', 61342, 27366),
(13550, 0, 0, 'I need a ride to the top of the statue.', 58416, 27366),
(13551, 0, 0, 'Did someone say they needed jade?', 58442, 27366),
(13550, 1, 0, 'I\'ve got a jade delivery for you.', 58443, 27366),
(13553, 0, 0, 'I\'ve got your jade right here.', 58441, 27366),
(13549, 0, 0, 'I\'ve got a new jade shipment for you.', 58444, 27366),
(14941, 0, 1, 'I want to browse your goods.', 3370, 27366),
(13396, 1, 0, 'Wait, I\'ve changed my mind about my egg.', 57017, 27366),
(13401, 2, 0, 'I would like a yellow serpent egg.', 57021, 27366),
(13401, 1, 0, 'I would like a green serpent egg.', 57020, 27366),
(13401, 0, 0, 'I would like a blue serpent egg.', 57019, 27366),
(13058, 0, 0, 'Put down your fork, and pick up your fists! I challenge you!', 53218, 27366),
(13054, 0, 0, 'Wanna fight?', 53202, 27366),
(13057, 0, 0, 'I challenge you to a fight, Husshun!', 53211, 27366),
(13059, 0, 0, 'Let\'s fight!', 59915, 27366), -- OptionBroadcastTextID: 53229 - 59915
(13072, 1, 0, 'I am certain. Let\'s move on to the fighting.', 53379, 27366),
(13072, 0, 0, 'Fine. Let\'s proceed with the introductions.', 53378, 27366),
(13070, 2, 0, 'I don\'t need any introductions, old man. Let\'s skip ahead to the good part.', 53377, 27366),
(13070, 0, 0, 'I\'m ready to be introduced to the instructors, High Elder.', 53375, 27366),
(13105, 0, 0, 'What is this place?', 136659, 27366), -- OptionBroadcastTextID: 18411 - 39050 - 53647 - 60157 - 66591 - 94147 - 136659
(14624, 0, 3, 'Train me in Mining.', 47116, 27366),
(14649, 8, 25, 'Queue for Greenstone Village.', 64701, 27366),
(14626, 1, 1, 'I would like to buy from you.', 14967, 27366), -- OptionBroadcastTextID: 2583 - 6399 - 7142 - 9992 - 14967
(14626, 0, 3, 'Train me in Blacksmithing.', 47110, 27366),
(14625, 0, 3, 'Train me in Jewelcrafting.', 47114, 27366),
(13226, 0, 0, 'Challenge the Pandriarch.', 54783, 27366),
(13225, 0, 0, 'Challenge the Pandriarch.', 54783, 27366),
(13227, 0, 0, 'Challenge the Pandriarch.', 54783, 27366),
(13291, 0, 3, 'Tell me about Inscription.', 47149, 27366),
(13808, 0, 1, 'I would like to buy from you.', 14967, 27366), -- OptionBroadcastTextID: 2583 - 6399 - 7142 - 9992 - 14967
(13427, 5, 0, 'Are these serpent hatchlings suitable for pet battles?', 66345, 27366),
(13286, 1, 0, 'Have you seen Lo Wanderbrew?', 55738, 27366), -- OptionBroadcastTextID: 55729 - 55738
(13286, 0, 0, 'I\'m ready to see Lorewalker Cho.', 55718, 27366),
(13530, 1, 1, 'I would like to buy from you.', 14967, 27366), -- OptionBroadcastTextID: 2583 - 6399 - 7142 - 9992 - 14967
(13137, 0, 0, 'Where is Shin?', 53908, 27366),
(13110, 0, 0, 'What happened out here?', 54167, 27366),
(13109, 0, 0, 'It\'s safe now.  You can come down.', 53675, 27366),
(13552, 0, 0, 'I need a ride to the bottom of the statue.', 58419, 27366),
(13374, 2, 1, 'I would like to buy from you.', 14967, 27356), -- OptionBroadcastTextID: 2583 - 6399 - 7142 - 9992 - 14967
(13374, 1, 5, 'Make this inn your home.', 2822, 27356),
(13283, 1, 3, 'I seek training in Pandaren cooking.', 65287, 27356),
(13283, 0, 1, 'I would like to buy from you.', 14967, 27356), -- OptionBroadcastTextID: 2583 - 6399 - 7142 - 9992 - 14967
(13782, 0, 1, 'I would like to buy from you.', 14967, 27356), -- OptionBroadcastTextID: 2583 - 6399 - 7142 - 9992 - 14967
(14628, 1, 1, 'Let me browse your goods.', 8097, 27356), -- OptionBroadcastTextID: 2823 - 7509 - 8097
(14628, 0, 3, 'Train me in Alchemy.', 47109, 27356),
(13538, 1, 0, 'I would like to travel to Dawn\'s Blossom.', 58233, 27356),
(13538, 0, 2, 'Show me where I can fly.', 12271, 27356),
(13254, 0, 0, 'It is time to go home, Prince Anduin.', 55156, 27356),
(13531, 3, 0, 'Can you help me find the White Pawn?', 54862, 27356),
(13531, 2, 0, 'How can I help the jinyu win against those monkey savages?', 54861, 27356),
(13531, 1, 0, 'What is this land? Why has its presence been hidden for centuries?', 54860, 27356),
(13531, 0, 0, 'Who are you... WHAT are you?', 54859, 27356), -- OptionBroadcastTextID: 54399 - 54859
(14280, 3, 0, '<Paint something heroic.>', 63367, 27356),
(14280, 2, 0, '<Paint something abstract.>', 63366, 27356),
(14280, 0, 0, '<Paint a Portrait of Prince Anduin.>', 62649, 27356),
(13272, 3, 0, 'Will these daggers help?', 55416, 27356),
(13272, 2, 0, 'This spellcaster\'s staff is for you.', 55415, 27356),
(13272, 1, 0, 'Take this book of healing prayers.', 55413, 27356),
(13272, 0, 0, 'You might need this shield.', 55412, 27356),
(13274, 3, 0, 'Will these daggers help?', 55416, 27356),
(13274, 2, 0, 'This spellcaster\'s staff is for you.', 55415, 27356),
(13274, 1, 0, 'Take this book of healing prayers.', 55413, 27356),
(13274, 0, 0, 'You might need this shield.', 55412, 27356),
(13273, 3, 0, 'Will these daggers help?', 55416, 27356),
(13273, 2, 0, 'This spellcaster\'s staff is for you.', 55415, 27356),
(13273, 1, 0, 'Take this book of healing prayers.', 55413, 27356),
(13273, 0, 0, 'You might need this shield.', 55412, 27356),
(13271, 3, 0, 'Will these daggers help?', 55416, 27356),
(13271, 2, 0, 'This spellcaster\'s staff is for you.', 55415, 27356),
(13271, 1, 0, 'Take this book of healing prayers.', 55413, 27356),
(13271, 0, 0, 'You might need this shield.', 55412, 27356),
(13265, 0, 3, 'What can you teach me?', 9980, 27356),
(13128, 0, 0, 'Can you help us? Our friend is injured.', 53800, 27356),
(13115, 0, 0, 'You did well, Agent Kearnen. Now save your energy... we\'ll fend them off.', 53765, 27356),
(13250, 0, 0, 'I have brought the items for the ceremony.', 55031, 27356),
(13281, 1, 0, 'What are you doing?', 120848, 27356), -- OptionBroadcastTextID: 16901 - 58049 - 79561 - 104081 - 120848
(13510, 0, 0, 'My friends and I come with peaceful intentions.', 58050, 27356),
(13250, 1, 0, 'I come from the Alliance. We wish to be allies, not enemies.', 58051, 27356),
(13509, 0, 0, 'Please allow us a chance to prove our friendship. We wish you no harm.', 58048, 27356),
(13809, 0, 5, 'Make this inn your home.', 2822, 27356),
(13312, 1, 3, 'What can you teach me?', 9980, 27356),
(14918, 0, 0, 'What of Jor Jor? He seems to protect the mayor.', 67155, 27356),
(14912, 0, 0, 'Please, don\'t cry. What happened next?', 67121, 27356),
(14913, 0, 0, 'What\'s wrong?', 67118, 27356),
(15110, 0, 1, 'What brews do you have for sale?', 68465, 27356),
(14935, 1, 1, 'Let me browse your goods.', 8097, 27356), -- OptionBroadcastTextID: 2823 - 7509 - 8097
(14935, 0, 5, 'Make this inn your home.', 2822, 27356),
(15099, 0, 3, 'Train me in Herbalism.', 47112, 27356),
(15100, 0, 3, 'Train me in Skinning.', 47117, 27356),
(14926, 0, 1, 'Let me browse your wares.', 83214, 27356), -- OptionBroadcastTextID: 67573 - 68470 - 83214
(15098, 0, 3, 'Train me in Mining.', 47116, 27356),
(14971, 1, 0, 'You really have it in for the Horde, don\'t you?', 68469, 27356),
(14971, 0, 0, 'I am ready to depart.', 67429, 27356),
(15111, 0, 0, 'I am ready to depart.', 67429, 27356),
(11920, 0, 1, 'I would like to buy from you.', 14967, 27326), -- OptionBroadcastTextID: 2583 - 6399 - 7142 - 9992 - 14967
(12591, 0, 1, 'I wish to browse your wares.', 38807, 27291), -- OptionBroadcastTextID: 4424 - 9818 - 12631 - 13966 - 14925 - 15955 - 16125 - 16127 - 17085 - 18217 - 19466 - 38807
(11535, 0, 0, 'Hexascrub, let me see that merciless one again.', 41660, 27291),
(11574, 0, 0, 'Why are you upside-down?', 41907, 27291),
(11581, 0, 0, '...', 131549, 27291), -- OptionBroadcastTextID: 11044 - 38461 - 41915 - 48348 - 49154 - 50215 - 56293 - 62516 - 69357 - 92198 - 100869 - 100895 - 100974 - 120179 - 130188 - 131549
(11580, 0, 0, 'I really need to get going now.', 41914, 27291),
(11579, 0, 0, 'That\'s too bad.  Anyhow...', 41913, 27291),
(11578, 0, 0, 'Sounds impressive.', 41912, 27291),
(11577, 0, 0, 'How did you get all the way over here, then?', 41911, 27291),
(11576, 0, 0, 'Fascinating.', 111681, 27291), -- OptionBroadcastTextID: 17050 - 19389 - 41909 - 52944 - 111681
(11575, 0, 0, 'Why is that?', 66489, 27291), -- OptionBroadcastTextID: 41908 - 66489
(11535, 7, 0, 'Here, I made a Promising Fuel Sample.  Three parts hammerhead and two parts remora.', 42016, 27291),
(11592, 0, 0, 'Mix the samples together!', 42003, 27291),
(11535, 1, 0, 'Here, I made a Billowing Fuel Sample.  It\'s really smoky!', 42009, 27291),
(11535, 5, 0, 'Here, I made a Smoky Fuel Sample.  Pretty, isn\'t it?', 42014, 27291),
(11535, 3, 0, 'Here, I made an Anemic Fuel Sample.  It seems... weak.', 42011, 27291),
(11535, 2, 0, 'Here, I made an Atomic Fuel Sample.  It seems to be a little too hot.', 42010, 27291),
(11477, 0, 0, 'I\'m ready to begin the assault on the terrace.', 41193, 27291),
(11525, 1, 0, 'Let\'s speak with Nespirah.', 41530, 27291),
(11525, 0, 0, 'Whenever you\'re ready, Duarn.', 41467, 27291),
(11352, 5, 0, 'Can I have an Earth Elemental Totem instead?', 40250, 27291),
(11352, 4, 0, 'Can I have a Stoneskin Totem instead?', 40264, 27291),
(11352, 3, 0, 'Can I have a Strength of Earth Totem instead?', 40248, 27291),
(11352, 2, 0, 'Can I have a Stoneclaw Totem instead?', 40247, 27291),
(11352, 1, 0, 'Can I have an Earthbind Totem instead?', 40246, 27291),
(11608, 0, 0, 'I am ready to join you in the vision, Farseer.', 42108, 27291),
(17546, 0, 0, 'I need you to come on patrol with me.', 81638, 27602),
(17557, 0, 0, 'I need you to come on patrol with me.', 81638, 27602),
(17104, 0, 0, 'Let\'s go.', 128698, 27602), -- OptionBroadcastTextID: 15894 - 57655 - 60204 - 62002 - 75830 - 77209 - 78160 - 78305 - 108064 - 125346 - 129809 - 129792 - 128698
(16707, 1, 0, 'I am needed urgently at the Iron Docks.', 87474, 27602),
(16665, 0, 0, 'So getting that bloom back might fix things... interesting...', 84060, 27602),
(16664, 0, 0, 'What were you supposed to do?', 84058, 27602),
(16662, 0, 0, 'Thank you for not killing me.  What duty have you failed?', 84054, 27602),
(16793, 0, 0, 'No one should become fertilizer for these monsters.  How did you come to be here?', 85353, 27602),
(16792, 0, 0, 'I doubt he took that well...', 85355, 27602),
(16329, 0, 0, 'What?', 127498, 27602), -- OptionBroadcastTextID: 1338 - 7652 - 12033 - 20788 - 25383 - 27318 - 27770 - 38871 - 63178 - 65655 - 67509 - 69196 - 72224 - 80688 - 92205 - 99352 - 114216 - 120710 - 121345 - 122235 - 122670 - 127498
(18867, 1, 3, 'Train me in the ways of herbalism.', 15944, 27602),
(16777, 1, 0, 'Brightblade?  That name sounds familiar...', 90017, 27602),
(17203, 0, 0, 'I admire your morals.  Carry on.', 90102, 27602),
(16686, 0, 0, '<Feed Sappy.>', 84326, 27602),
(16895, 0, 0, 'Thaelin is on his way soon.', 90316, 27602),
(16542, 0, 0, 'D\'kaan is coming with help.', 83161, 27602),
(16538, 0, 0, 'D\'kaan is coming with help.', 83161, 27602),
(16539, 0, 0, 'D\'kaan is coming with help.', 83161, 27602),
(18491, 0, 0, 'Let us begin the invasion.', 92740, 27602),
(18486, 5, 28, 'Start construction on our first transport.', 98383, 27602),
(18189, 0, 0, 'Take me back to the garrison.', 92715, 27602),
(16762, 2, 2, 'Show me where I can fly.', 12271, 27602),
(16849, 1, 3, 'Train me in Inscription.', 88801, 27602), -- OptionBroadcastTextID: 47113 - 88801
(16849, 0, 3, 'Train me in Archaeology.', 88800, 27602), -- OptionBroadcastTextID: 88647 - 88800
(16703, 0, 0, 'I am ready to fly, Ka\'alu.', 84668, 27602),
(16515, 0, 0, 'I\'m ready, High Ravenspeaker.', 85116, 27602),
(17246, 0, 1, 'Show me your wares.', 90189, 27602), -- OptionBroadcastTextID: 58437 - 90189
(16822, 0, 0, 'Accept Terokk\'s power.', 85064, 27602),
(16737, 3, 0, 'Call upon Terokk.', 85436, 27602),
(16737, 1, 0, 'Touch the bangle to witness Terokk\'s fall.', 85063, 27602),
(16737, 0, 0, 'Touch the wingblades to witness one of Terokk\'s legends.', 84937, 27602),
(16651, 0, 0, '<The waters begin to stir.>', 81817, 27602),
(16502, 0, 0, 'Search him for the gavel.', 86757, 27602),
(16876, 1, 2, 'Show me where I can fly.', 12271, 27602),
(16977, 0, 0, 'I am ready Anzu, we will not fail.', 87145, 27602),
(17275, 0, 0, 'It\'s over, Jacob. Come quietly and we\'ll get you on the first gryphon to prison for treason.', 90371, 27602),
(16854, 0, 0, 'Administer the antidote to Kolrigg.', 85820, 27602),
(16817, 0, 0, 'Take me back to my outpost.', 85529, 27602),
(16762, 0, 0, 'Take me to Shadow\'s Vigil.', 85065, 27602),
(16652, 0, 0, 'Show the spectral essences to Alice.', 83993, 27602);

UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=8097, `VerifiedBuild`=27377 WHERE (`MenuId`=9868 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=8097 WHERE (`MenuId`=12602 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=124289, `VerifiedBuild`=27326 WHERE (`MenuId`=12130 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=8097, `VerifiedBuild`=27326 WHERE (`MenuId`=342 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=8097, `VerifiedBuild`=27326 WHERE (`MenuId`=342 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=46718, `VerifiedBuild`=27326 WHERE (`MenuId`=12143 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=46718, `VerifiedBuild`=27326 WHERE (`MenuId`=12143 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=46718, `VerifiedBuild`=27326 WHERE (`MenuId`=12143 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=46648, `VerifiedBuild`=27326 WHERE (`MenuId`=12139 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=46648, `VerifiedBuild`=27326 WHERE (`MenuId`=12139 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=46648, `VerifiedBuild`=27326 WHERE (`MenuId`=12139 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=46426, `VerifiedBuild`=27326 WHERE (`MenuId`=12116 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=46424, `VerifiedBuild`=27326 WHERE (`MenuId`=12115 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=46422, `VerifiedBuild`=27326 WHERE (`MenuId`=12114 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=46420, `VerifiedBuild`=27326 WHERE (`MenuId`=12113 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=46426, `VerifiedBuild`=27326 WHERE (`MenuId`=12116 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=46424, `VerifiedBuild`=27326 WHERE (`MenuId`=12115 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=46422, `VerifiedBuild`=27326 WHERE (`MenuId`=12114 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=46420, `VerifiedBuild`=27326 WHERE (`MenuId`=12113 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=46426, `VerifiedBuild`=27326 WHERE (`MenuId`=12116 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=46424, `VerifiedBuild`=27326 WHERE (`MenuId`=12115 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=46422, `VerifiedBuild`=27326 WHERE (`MenuId`=12114 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=46420, `VerifiedBuild`=27326 WHERE (`MenuId`=12113 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=46426, `VerifiedBuild`=27326 WHERE (`MenuId`=12116 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=46424, `VerifiedBuild`=27326 WHERE (`MenuId`=12115 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=46422, `VerifiedBuild`=27326 WHERE (`MenuId`=12114 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=46420, `VerifiedBuild`=27326 WHERE (`MenuId`=12113 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=47016, `VerifiedBuild`=27326 WHERE (`MenuId`=12165 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=47016, `VerifiedBuild`=27326 WHERE (`MenuId`=12165 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=47016, `VerifiedBuild`=27326 WHERE (`MenuId`=12165 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=47016, `VerifiedBuild`=27326 WHERE (`MenuId`=12165 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=47556, `VerifiedBuild`=27326 WHERE (`MenuId`=12247 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=47620, `VerifiedBuild`=27326 WHERE (`MenuId`=12266 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=47614, `VerifiedBuild`=27326 WHERE (`MenuId`=12266 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=47620, `VerifiedBuild`=27326 WHERE (`MenuId`=12266 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=47614, `VerifiedBuild`=27326 WHERE (`MenuId`=12266 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=47620, `VerifiedBuild`=27326 WHERE (`MenuId`=12266 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=47614, `VerifiedBuild`=27326 WHERE (`MenuId`=12266 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=47620, `VerifiedBuild`=27326 WHERE (`MenuId`=12266 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=47614, `VerifiedBuild`=27326 WHERE (`MenuId`=12266 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=47620, `VerifiedBuild`=27326 WHERE (`MenuId`=12266 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=47614, `VerifiedBuild`=27326 WHERE (`MenuId`=12266 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=47620, `VerifiedBuild`=27326 WHERE (`MenuId`=12266 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=47614, `VerifiedBuild`=27326 WHERE (`MenuId`=12266 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=132063, `VerifiedBuild`=27326 WHERE (`MenuId`=12055 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=132063, `VerifiedBuild`=27326 WHERE (`MenuId`=12055 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionText`='Here are some spare parts. I\'ll cover you while you make repairs!', `OptionBroadcastTextId`=45717, `VerifiedBuild`=27326 WHERE (`MenuId`=12042 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=8097, `VerifiedBuild`=27178 WHERE (`MenuId`=7809 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=8097, `VerifiedBuild`=27178 WHERE (`MenuId`=7809 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=8097, `VerifiedBuild`=27178 WHERE (`MenuId`=7809 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=8097, `VerifiedBuild`=27178 WHERE (`MenuId`=7809 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=8097, `VerifiedBuild`=27178 WHERE (`MenuId`=7809 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=2822, `VerifiedBuild`=27602 WHERE (`MenuId`=7481 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=8097, `VerifiedBuild`=27602 WHERE (`MenuId`=16524 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=8097, `VerifiedBuild`=27602 WHERE (`MenuId`=342 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=14967, `VerifiedBuild`=27602 WHERE (`MenuId`=21043 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=14967, `VerifiedBuild`=27602 WHERE (`MenuId`=21043 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=8097, `VerifiedBuild`=27377 WHERE (`MenuId`=9868 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=8097, `VerifiedBuild`=27377 WHERE (`MenuId`=9868 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=8097, `VerifiedBuild`=27377 WHERE (`MenuId`=9868 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=52653, `VerifiedBuild`=27326 WHERE (`MenuId`=12943 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=52583, `VerifiedBuild`=27326 WHERE (`MenuId`=12940 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=52583, `VerifiedBuild`=27326 WHERE (`MenuId`=12940 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45532, `VerifiedBuild`=27326 WHERE (`MenuId`=12017 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45533, `VerifiedBuild`=27326 WHERE (`MenuId`=12017 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45532, `VerifiedBuild`=27326 WHERE (`MenuId`=12017 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45533, `VerifiedBuild`=27326 WHERE (`MenuId`=12017 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45533, `VerifiedBuild`=27326 WHERE (`MenuId`=12015 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45532, `VerifiedBuild`=27326 WHERE (`MenuId`=12015 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=44674, `VerifiedBuild`=27326 WHERE (`MenuId`=11873 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=44674, `VerifiedBuild`=27326 WHERE (`MenuId`=11872 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=44674, `VerifiedBuild`=27326 WHERE (`MenuId`=11873 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=44674, `VerifiedBuild`=27326 WHERE (`MenuId`=11872 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=44674, `VerifiedBuild`=27326 WHERE (`MenuId`=11872 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=44674, `VerifiedBuild`=27326 WHERE (`MenuId`=11872 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45532, `VerifiedBuild`=27326 WHERE (`MenuId`=12017 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45533, `VerifiedBuild`=27326 WHERE (`MenuId`=12017 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45532, `VerifiedBuild`=27326 WHERE (`MenuId`=12017 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45533, `VerifiedBuild`=27326 WHERE (`MenuId`=12017 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=43563, `VerifiedBuild`=27326 WHERE (`MenuId`=11739 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=43650, `VerifiedBuild`=27326 WHERE (`MenuId`=11689 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=43720, `VerifiedBuild`=27326 WHERE (`MenuId`=11916 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=43720, `VerifiedBuild`=27326 WHERE (`MenuId`=11916 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=44526, `VerifiedBuild`=27326 WHERE (`MenuId`=12227 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=44526, `VerifiedBuild`=27326 WHERE (`MenuId`=12227 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=44526, `VerifiedBuild`=27326 WHERE (`MenuId`=12227 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=52559, `VerifiedBuild`=27326 WHERE (`MenuId`=12930 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=52559, `VerifiedBuild`=27326 WHERE (`MenuId`=12930 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=52535, `VerifiedBuild`=27326 WHERE (`MenuId`=12938 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45532, `VerifiedBuild`=27144 WHERE (`MenuId`=11520 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45532, `VerifiedBuild`=27144 WHERE (`MenuId`=11520 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45532, `VerifiedBuild`=27144 WHERE (`MenuId`=11520 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45532, `VerifiedBuild`=27144 WHERE (`MenuId`=11520 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45532, `VerifiedBuild`=27144 WHERE (`MenuId`=11520 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45532, `VerifiedBuild`=27144 WHERE (`MenuId`=11520 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45532, `VerifiedBuild`=27144 WHERE (`MenuId`=11520 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45532, `VerifiedBuild`=27144 WHERE (`MenuId`=11520 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=52077, `VerifiedBuild`=27843 WHERE (`MenuId`=421 AND `OptionIndex`=16);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=106243, `VerifiedBuild`=27843 WHERE (`MenuId`=421 AND `OptionIndex`=15);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=78976, `VerifiedBuild`=27843 WHERE (`MenuId`=421 AND `OptionIndex`=13);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=52071, `VerifiedBuild`=27843 WHERE (`MenuId`=421 AND `OptionIndex`=12);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45758, `VerifiedBuild`=27843 WHERE (`MenuId`=421 AND `OptionIndex`=11);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=48811, `VerifiedBuild`=27843 WHERE (`MenuId`=421 AND `OptionIndex`=10);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45768, `VerifiedBuild`=27843 WHERE (`MenuId`=421 AND `OptionIndex`=9);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=99684, `VerifiedBuild`=27843 WHERE (`MenuId`=421 AND `OptionIndex`=7);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=52066, `VerifiedBuild`=27843 WHERE (`MenuId`=421 AND `OptionIndex`=6);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=51347, `VerifiedBuild`=27843 WHERE (`MenuId`=421 AND `OptionIndex`=5);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=52063, `VerifiedBuild`=27843 WHERE (`MenuId`=421 AND `OptionIndex`=4);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45763, `VerifiedBuild`=27843 WHERE (`MenuId`=421 AND `OptionIndex`=3);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=51346, `VerifiedBuild`=27843 WHERE (`MenuId`=421 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=52058, `VerifiedBuild`=27843 WHERE (`MenuId`=421 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45383, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=15);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45382, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=14);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=129194, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=13);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45381, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=11);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=44629, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=10);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45380, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=9);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45379, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=8);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45378, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=7);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45376, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=6);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=78584, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=5);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=44627, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=4);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=6351, `VerifiedBuild`=27843 WHERE (`MenuId`=11845 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45383, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=15);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45382, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=14);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=129194, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=13);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45381, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=11);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=44629, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=10);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45380, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=9);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45379, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=8);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45378, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=7);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45376, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=6);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=78584, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=5);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=44627, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=4);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=52077, `VerifiedBuild`=27843 WHERE (`MenuId`=421 AND `OptionIndex`=16);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=106243, `VerifiedBuild`=27843 WHERE (`MenuId`=421 AND `OptionIndex`=15);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=78976, `VerifiedBuild`=27843 WHERE (`MenuId`=421 AND `OptionIndex`=13);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=52071, `VerifiedBuild`=27843 WHERE (`MenuId`=421 AND `OptionIndex`=12);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45758, `VerifiedBuild`=27843 WHERE (`MenuId`=421 AND `OptionIndex`=11);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=48811, `VerifiedBuild`=27843 WHERE (`MenuId`=421 AND `OptionIndex`=10);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45768, `VerifiedBuild`=27843 WHERE (`MenuId`=421 AND `OptionIndex`=9);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=99684, `VerifiedBuild`=27843 WHERE (`MenuId`=421 AND `OptionIndex`=7);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=52066, `VerifiedBuild`=27843 WHERE (`MenuId`=421 AND `OptionIndex`=6);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=51347, `VerifiedBuild`=27843 WHERE (`MenuId`=421 AND `OptionIndex`=5);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=52063, `VerifiedBuild`=27843 WHERE (`MenuId`=421 AND `OptionIndex`=4);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45763, `VerifiedBuild`=27843 WHERE (`MenuId`=421 AND `OptionIndex`=3);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=51346, `VerifiedBuild`=27843 WHERE (`MenuId`=421 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=52058, `VerifiedBuild`=27843 WHERE (`MenuId`=421 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45383, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=15);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45382, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=14);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=129194, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=13);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45381, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=11);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=44629, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=10);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45380, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=9);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45379, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=8);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45378, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=7);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45376, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=6);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=78584, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=5);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=44627, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=4);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=52077, `VerifiedBuild`=27843 WHERE (`MenuId`=421 AND `OptionIndex`=16);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=106243, `VerifiedBuild`=27843 WHERE (`MenuId`=421 AND `OptionIndex`=15);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=78976, `VerifiedBuild`=27843 WHERE (`MenuId`=421 AND `OptionIndex`=13);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=52071, `VerifiedBuild`=27843 WHERE (`MenuId`=421 AND `OptionIndex`=12);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45758, `VerifiedBuild`=27843 WHERE (`MenuId`=421 AND `OptionIndex`=11);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=48811, `VerifiedBuild`=27843 WHERE (`MenuId`=421 AND `OptionIndex`=10);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45768, `VerifiedBuild`=27843 WHERE (`MenuId`=421 AND `OptionIndex`=9);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=99684, `VerifiedBuild`=27843 WHERE (`MenuId`=421 AND `OptionIndex`=7);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=52066, `VerifiedBuild`=27843 WHERE (`MenuId`=421 AND `OptionIndex`=6);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=51347, `VerifiedBuild`=27843 WHERE (`MenuId`=421 AND `OptionIndex`=5);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=52063, `VerifiedBuild`=27843 WHERE (`MenuId`=421 AND `OptionIndex`=4);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45763, `VerifiedBuild`=27843 WHERE (`MenuId`=421 AND `OptionIndex`=3);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=51346, `VerifiedBuild`=27843 WHERE (`MenuId`=421 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=52058, `VerifiedBuild`=27843 WHERE (`MenuId`=421 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45383, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=15);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45382, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=14);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=129194, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=13);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45381, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=11);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=44629, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=10);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45380, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=9);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45379, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=8);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45378, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=7);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45376, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=6);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=78584, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=5);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=44627, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=4);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=52077, `VerifiedBuild`=27843 WHERE (`MenuId`=421 AND `OptionIndex`=16);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=106243, `VerifiedBuild`=27843 WHERE (`MenuId`=421 AND `OptionIndex`=15);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=78976, `VerifiedBuild`=27843 WHERE (`MenuId`=421 AND `OptionIndex`=13);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=52071, `VerifiedBuild`=27843 WHERE (`MenuId`=421 AND `OptionIndex`=12);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45758, `VerifiedBuild`=27843 WHERE (`MenuId`=421 AND `OptionIndex`=11);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=48811, `VerifiedBuild`=27843 WHERE (`MenuId`=421 AND `OptionIndex`=10);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45768, `VerifiedBuild`=27843 WHERE (`MenuId`=421 AND `OptionIndex`=9);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=99684, `VerifiedBuild`=27843 WHERE (`MenuId`=421 AND `OptionIndex`=7);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=52066, `VerifiedBuild`=27843 WHERE (`MenuId`=421 AND `OptionIndex`=6);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=51347, `VerifiedBuild`=27843 WHERE (`MenuId`=421 AND `OptionIndex`=5);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=52063, `VerifiedBuild`=27843 WHERE (`MenuId`=421 AND `OptionIndex`=4);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45763, `VerifiedBuild`=27843 WHERE (`MenuId`=421 AND `OptionIndex`=3);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=51346, `VerifiedBuild`=27843 WHERE (`MenuId`=421 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=52058, `VerifiedBuild`=27843 WHERE (`MenuId`=421 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45383, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=15);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45382, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=14);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=129194, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=13);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45381, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=11);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=44629, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=10);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45380, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=9);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45379, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=8);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45378, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=7);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45376, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=6);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=78584, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=5);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=44627, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=4);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=52077, `VerifiedBuild`=27843 WHERE (`MenuId`=421 AND `OptionIndex`=16);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=106243, `VerifiedBuild`=27843 WHERE (`MenuId`=421 AND `OptionIndex`=15);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=78976, `VerifiedBuild`=27843 WHERE (`MenuId`=421 AND `OptionIndex`=13);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=52071, `VerifiedBuild`=27843 WHERE (`MenuId`=421 AND `OptionIndex`=12);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45758, `VerifiedBuild`=27843 WHERE (`MenuId`=421 AND `OptionIndex`=11);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=48811, `VerifiedBuild`=27843 WHERE (`MenuId`=421 AND `OptionIndex`=10);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45768, `VerifiedBuild`=27843 WHERE (`MenuId`=421 AND `OptionIndex`=9);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=99684, `VerifiedBuild`=27843 WHERE (`MenuId`=421 AND `OptionIndex`=7);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=52066, `VerifiedBuild`=27843 WHERE (`MenuId`=421 AND `OptionIndex`=6);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=51347, `VerifiedBuild`=27843 WHERE (`MenuId`=421 AND `OptionIndex`=5);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=52063, `VerifiedBuild`=27843 WHERE (`MenuId`=421 AND `OptionIndex`=4);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45763, `VerifiedBuild`=27843 WHERE (`MenuId`=421 AND `OptionIndex`=3);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=51346, `VerifiedBuild`=27843 WHERE (`MenuId`=421 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=52058, `VerifiedBuild`=27843 WHERE (`MenuId`=421 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45383, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=15);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45382, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=14);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=129194, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=13);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45381, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=11);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=44629, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=10);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45380, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=9);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45379, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=8);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45378, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=7);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45376, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=6);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=78584, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=5);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=44627, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=4);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=52077, `VerifiedBuild`=27843 WHERE (`MenuId`=421 AND `OptionIndex`=16);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=106243, `VerifiedBuild`=27843 WHERE (`MenuId`=421 AND `OptionIndex`=15);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=78976, `VerifiedBuild`=27843 WHERE (`MenuId`=421 AND `OptionIndex`=13);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=52071, `VerifiedBuild`=27843 WHERE (`MenuId`=421 AND `OptionIndex`=12);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45758, `VerifiedBuild`=27843 WHERE (`MenuId`=421 AND `OptionIndex`=11);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=48811, `VerifiedBuild`=27843 WHERE (`MenuId`=421 AND `OptionIndex`=10);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45768, `VerifiedBuild`=27843 WHERE (`MenuId`=421 AND `OptionIndex`=9);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=99684, `VerifiedBuild`=27843 WHERE (`MenuId`=421 AND `OptionIndex`=7);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=52066, `VerifiedBuild`=27843 WHERE (`MenuId`=421 AND `OptionIndex`=6);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=51347, `VerifiedBuild`=27843 WHERE (`MenuId`=421 AND `OptionIndex`=5);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=52063, `VerifiedBuild`=27843 WHERE (`MenuId`=421 AND `OptionIndex`=4);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45763, `VerifiedBuild`=27843 WHERE (`MenuId`=421 AND `OptionIndex`=3);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=51346, `VerifiedBuild`=27843 WHERE (`MenuId`=421 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=52058, `VerifiedBuild`=27843 WHERE (`MenuId`=421 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45383, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=15);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45382, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=14);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=129194, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=13);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45381, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=11);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=44629, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=10);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45380, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=9);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45379, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=8);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45378, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=7);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45376, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=6);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=78584, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=5);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=44627, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=4);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=129104, `VerifiedBuild`=27843 WHERE (`MenuId`=12243 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45383, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=15);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45382, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=14);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=129194, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=13);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45381, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=11);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=44629, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=10);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45380, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=9);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45379, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=8);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45378, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=7);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45376, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=6);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=78584, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=5);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=44627, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=4);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=129104, `VerifiedBuild`=27843 WHERE (`MenuId`=12243 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45383, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=15);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45382, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=14);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=129194, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=13);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45381, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=11);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=44629, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=10);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45380, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=9);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45379, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=8);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45378, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=7);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45376, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=6);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=78584, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=5);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=44627, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=4);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=129104, `VerifiedBuild`=27843 WHERE (`MenuId`=12243 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45383, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=15);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45382, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=14);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=129194, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=13);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45381, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=11);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=44629, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=10);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45380, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=9);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45379, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=8);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45378, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=7);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45376, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=6);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=78584, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=5);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=44627, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=4);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=129104, `VerifiedBuild`=27843 WHERE (`MenuId`=12243 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45383, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=15);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45382, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=14);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=129194, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=13);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45381, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=11);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=44629, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=10);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45380, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=9);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45379, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=8);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45378, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=7);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45376, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=6);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=78584, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=5);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=44627, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=4);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=129104, `VerifiedBuild`=27843 WHERE (`MenuId`=12243 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45383, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=15);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45382, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=14);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=129194, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=13);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45381, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=11);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=44629, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=10);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45380, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=9);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45379, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=8);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45378, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=7);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45376, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=6);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=78584, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=5);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=44627, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=4);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=129104, `VerifiedBuild`=27843 WHERE (`MenuId`=12243 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45383, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=15);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45382, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=14);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=129194, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=13);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45381, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=11);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=44629, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=10);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45380, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=9);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45379, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=8);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45378, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=7);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45376, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=6);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=78584, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=5);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=44627, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=4);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=129104, `VerifiedBuild`=27843 WHERE (`MenuId`=12243 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45383, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=15);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45382, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=14);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=129194, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=13);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45381, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=11);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=44629, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=10);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45380, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=9);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45379, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=8);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45378, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=7);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45376, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=6);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=78584, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=5);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=44627, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=4);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=6351, `VerifiedBuild`=27843 WHERE (`MenuId`=11845 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45383, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=15);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45382, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=14);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=129194, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=13);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45381, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=11);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=44629, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=10);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45380, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=9);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45379, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=8);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45378, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=7);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45376, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=6);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=78584, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=5);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=44627, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=4);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=6351, `VerifiedBuild`=27843 WHERE (`MenuId`=11845 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45383, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=15);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45382, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=14);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=129194, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=13);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45381, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=11);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=44629, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=10);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45380, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=9);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45379, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=8);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45378, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=7);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45376, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=6);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=78584, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=5);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=44627, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=4);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=6351, `VerifiedBuild`=27843 WHERE (`MenuId`=11845 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45383, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=15);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45382, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=14);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=129194, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=13);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45381, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=11);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=44629, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=10);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45380, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=9);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45379, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=8);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45378, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=7);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45376, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=6);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=78584, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=5);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=44627, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=4);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=6351, `VerifiedBuild`=27843 WHERE (`MenuId`=11845 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45383, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=15);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45382, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=14);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=129194, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=13);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45381, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=11);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=44629, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=10);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45380, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=9);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45379, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=8);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45378, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=7);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45376, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=6);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=78584, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=5);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=44627, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=4);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=6351, `VerifiedBuild`=27843 WHERE (`MenuId`=11845 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45383, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=15);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45382, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=14);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=129194, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=13);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45381, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=11);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=44629, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=10);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45380, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=9);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45379, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=8);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45378, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=7);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45376, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=6);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=78584, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=5);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=44627, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=4);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=6351, `VerifiedBuild`=27843 WHERE (`MenuId`=11845 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45383, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=15);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45382, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=14);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=129194, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=13);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45381, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=11);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=44629, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=10);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45380, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=9);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45379, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=8);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45378, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=7);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45376, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=6);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=78584, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=5);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=44627, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=4);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=44629, `VerifiedBuild`=27843 WHERE (`MenuId`=3127 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=78584, `VerifiedBuild`=27843 WHERE (`MenuId`=3127 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=44627, `VerifiedBuild`=27843 WHERE (`MenuId`=3127 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45383, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=15);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45382, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=14);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=129194, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=13);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45381, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=11);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=44629, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=10);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45380, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=9);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45379, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=8);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45378, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=7);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45376, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=6);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=78584, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=5);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=44627, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=4);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=44629, `VerifiedBuild`=27843 WHERE (`MenuId`=3127 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=78584, `VerifiedBuild`=27843 WHERE (`MenuId`=3127 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=44627, `VerifiedBuild`=27843 WHERE (`MenuId`=3127 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45383, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=15);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45382, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=14);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=129194, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=13);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45381, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=11);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=44629, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=10);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45380, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=9);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45379, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=8);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45378, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=7);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45376, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=6);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=78584, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=5);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=44627, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=4);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=44629, `VerifiedBuild`=27843 WHERE (`MenuId`=3127 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=78584, `VerifiedBuild`=27843 WHERE (`MenuId`=3127 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=44627, `VerifiedBuild`=27843 WHERE (`MenuId`=3127 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45383, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=15);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45382, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=14);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=129194, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=13);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45381, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=11);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=44629, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=10);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45380, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=9);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45379, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=8);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45378, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=7);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45376, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=6);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=78584, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=5);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=44627, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=4);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=44629, `VerifiedBuild`=27843 WHERE (`MenuId`=3127 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=78584, `VerifiedBuild`=27843 WHERE (`MenuId`=3127 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=44627, `VerifiedBuild`=27843 WHERE (`MenuId`=3127 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45383, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=15);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45382, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=14);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=129194, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=13);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45381, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=11);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=44629, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=10);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45380, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=9);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45379, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=8);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45378, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=7);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45376, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=6);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=78584, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=5);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=44627, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=4);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=44629, `VerifiedBuild`=27843 WHERE (`MenuId`=3127 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=78584, `VerifiedBuild`=27843 WHERE (`MenuId`=3127 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=44627, `VerifiedBuild`=27843 WHERE (`MenuId`=3127 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45383, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=15);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45382, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=14);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=129194, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=13);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45381, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=11);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=44629, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=10);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45380, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=9);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45379, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=8);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45378, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=7);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45376, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=6);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=78584, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=5);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=44627, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=4);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=44629, `VerifiedBuild`=27843 WHERE (`MenuId`=3127 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=78584, `VerifiedBuild`=27843 WHERE (`MenuId`=3127 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=44627, `VerifiedBuild`=27843 WHERE (`MenuId`=3127 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45383, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=15);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45382, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=14);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=129194, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=13);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45381, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=11);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=44629, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=10);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45380, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=9);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45379, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=8);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45378, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=7);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45376, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=6);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=78584, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=5);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=44627, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=4);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45383, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=15);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45382, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=14);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=129194, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=13);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45381, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=11);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=44629, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=10);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45380, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=9);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45379, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=8);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45378, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=7);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45376, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=6);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=78584, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=5);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=44627, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=4);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45383, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=15);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45382, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=14);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=129194, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=13);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45381, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=11);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=44629, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=10);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45380, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=9);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45379, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=8);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45378, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=7);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45376, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=6);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=78584, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=5);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=44627, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=4);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45383, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=15);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45382, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=14);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=129194, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=13);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45381, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=11);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=44629, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=10);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45380, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=9);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45379, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=8);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45378, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=7);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45376, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=6);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=78584, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=5);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=44627, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=4);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45383, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=15);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45382, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=14);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=129194, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=13);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45381, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=11);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=44629, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=10);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45380, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=9);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45379, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=8);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45378, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=7);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45376, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=6);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=78584, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=5);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=44627, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=4);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=61849, `VerifiedBuild`=27843 WHERE (`MenuId`=401 AND `OptionIndex`=9);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45408, `VerifiedBuild`=27843 WHERE (`MenuId`=401 AND `OptionIndex`=8);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45407, `VerifiedBuild`=27843 WHERE (`MenuId`=401 AND `OptionIndex`=7);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45410, `VerifiedBuild`=27843 WHERE (`MenuId`=401 AND `OptionIndex`=6);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45406, `VerifiedBuild`=27843 WHERE (`MenuId`=401 AND `OptionIndex`=5);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45405, `VerifiedBuild`=27843 WHERE (`MenuId`=401 AND `OptionIndex`=4);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=48028, `VerifiedBuild`=27843 WHERE (`MenuId`=401 AND `OptionIndex`=3);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45404, `VerifiedBuild`=27843 WHERE (`MenuId`=401 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=50546, `VerifiedBuild`=27843 WHERE (`MenuId`=401 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45409, `VerifiedBuild`=27843 WHERE (`MenuId`=401 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45383, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=15);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45382, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=14);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=129194, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=13);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45381, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=11);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=44629, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=10);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45380, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=9);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45379, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=8);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45378, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=7);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45376, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=6);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=78584, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=5);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=44627, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=4);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=61849, `VerifiedBuild`=27843 WHERE (`MenuId`=401 AND `OptionIndex`=9);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45408, `VerifiedBuild`=27843 WHERE (`MenuId`=401 AND `OptionIndex`=8);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45407, `VerifiedBuild`=27843 WHERE (`MenuId`=401 AND `OptionIndex`=7);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45410, `VerifiedBuild`=27843 WHERE (`MenuId`=401 AND `OptionIndex`=6);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45406, `VerifiedBuild`=27843 WHERE (`MenuId`=401 AND `OptionIndex`=5);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45405, `VerifiedBuild`=27843 WHERE (`MenuId`=401 AND `OptionIndex`=4);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=48028, `VerifiedBuild`=27843 WHERE (`MenuId`=401 AND `OptionIndex`=3);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45404, `VerifiedBuild`=27843 WHERE (`MenuId`=401 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=50546, `VerifiedBuild`=27843 WHERE (`MenuId`=401 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45409, `VerifiedBuild`=27843 WHERE (`MenuId`=401 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45383, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=15);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45382, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=14);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=129194, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=13);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45381, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=11);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=44629, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=10);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45380, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=9);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45379, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=8);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45378, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=7);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45376, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=6);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=78584, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=5);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=44627, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=4);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=61849, `VerifiedBuild`=27843 WHERE (`MenuId`=401 AND `OptionIndex`=9);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45408, `VerifiedBuild`=27843 WHERE (`MenuId`=401 AND `OptionIndex`=8);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45407, `VerifiedBuild`=27843 WHERE (`MenuId`=401 AND `OptionIndex`=7);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45410, `VerifiedBuild`=27843 WHERE (`MenuId`=401 AND `OptionIndex`=6);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45406, `VerifiedBuild`=27843 WHERE (`MenuId`=401 AND `OptionIndex`=5);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45405, `VerifiedBuild`=27843 WHERE (`MenuId`=401 AND `OptionIndex`=4);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=48028, `VerifiedBuild`=27843 WHERE (`MenuId`=401 AND `OptionIndex`=3);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45404, `VerifiedBuild`=27843 WHERE (`MenuId`=401 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=50546, `VerifiedBuild`=27843 WHERE (`MenuId`=401 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45409, `VerifiedBuild`=27843 WHERE (`MenuId`=401 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45383, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=15);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45382, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=14);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=129194, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=13);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45381, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=11);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=44629, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=10);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45380, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=9);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45379, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=8);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45378, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=7);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45376, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=6);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=78584, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=5);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=44627, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=4);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=61849, `VerifiedBuild`=27843 WHERE (`MenuId`=401 AND `OptionIndex`=9);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45408, `VerifiedBuild`=27843 WHERE (`MenuId`=401 AND `OptionIndex`=8);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45407, `VerifiedBuild`=27843 WHERE (`MenuId`=401 AND `OptionIndex`=7);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45410, `VerifiedBuild`=27843 WHERE (`MenuId`=401 AND `OptionIndex`=6);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45406, `VerifiedBuild`=27843 WHERE (`MenuId`=401 AND `OptionIndex`=5);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45405, `VerifiedBuild`=27843 WHERE (`MenuId`=401 AND `OptionIndex`=4);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=48028, `VerifiedBuild`=27843 WHERE (`MenuId`=401 AND `OptionIndex`=3);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45404, `VerifiedBuild`=27843 WHERE (`MenuId`=401 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=50546, `VerifiedBuild`=27843 WHERE (`MenuId`=401 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45409, `VerifiedBuild`=27843 WHERE (`MenuId`=401 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45383, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=15);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45382, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=14);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=129194, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=13);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45381, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=11);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=44629, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=10);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45380, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=9);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45379, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=8);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45378, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=7);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45376, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=6);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=78584, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=5);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=44627, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=4);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=61849, `VerifiedBuild`=27843 WHERE (`MenuId`=401 AND `OptionIndex`=9);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45408, `VerifiedBuild`=27843 WHERE (`MenuId`=401 AND `OptionIndex`=8);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45407, `VerifiedBuild`=27843 WHERE (`MenuId`=401 AND `OptionIndex`=7);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45410, `VerifiedBuild`=27843 WHERE (`MenuId`=401 AND `OptionIndex`=6);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45406, `VerifiedBuild`=27843 WHERE (`MenuId`=401 AND `OptionIndex`=5);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45405, `VerifiedBuild`=27843 WHERE (`MenuId`=401 AND `OptionIndex`=4);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=48028, `VerifiedBuild`=27843 WHERE (`MenuId`=401 AND `OptionIndex`=3);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45404, `VerifiedBuild`=27843 WHERE (`MenuId`=401 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=50546, `VerifiedBuild`=27843 WHERE (`MenuId`=401 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45409, `VerifiedBuild`=27843 WHERE (`MenuId`=401 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45383, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=15);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45382, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=14);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=129194, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=13);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45381, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=11);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=44629, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=10);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45380, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=9);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45379, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=8);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45378, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=7);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45376, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=6);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=78584, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=5);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=44627, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=4);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=61849, `VerifiedBuild`=27843 WHERE (`MenuId`=401 AND `OptionIndex`=9);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45408, `VerifiedBuild`=27843 WHERE (`MenuId`=401 AND `OptionIndex`=8);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45407, `VerifiedBuild`=27843 WHERE (`MenuId`=401 AND `OptionIndex`=7);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45410, `VerifiedBuild`=27843 WHERE (`MenuId`=401 AND `OptionIndex`=6);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45406, `VerifiedBuild`=27843 WHERE (`MenuId`=401 AND `OptionIndex`=5);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45405, `VerifiedBuild`=27843 WHERE (`MenuId`=401 AND `OptionIndex`=4);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=48028, `VerifiedBuild`=27843 WHERE (`MenuId`=401 AND `OptionIndex`=3);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45404, `VerifiedBuild`=27843 WHERE (`MenuId`=401 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=50546, `VerifiedBuild`=27843 WHERE (`MenuId`=401 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45409, `VerifiedBuild`=27843 WHERE (`MenuId`=401 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45383, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=15);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45382, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=14);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=129194, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=13);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45381, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=11);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=44629, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=10);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45380, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=9);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45379, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=8);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45378, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=7);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45376, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=6);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=78584, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=5);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=44627, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=4);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=61849, `VerifiedBuild`=27843 WHERE (`MenuId`=401 AND `OptionIndex`=9);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45408, `VerifiedBuild`=27843 WHERE (`MenuId`=401 AND `OptionIndex`=8);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45407, `VerifiedBuild`=27843 WHERE (`MenuId`=401 AND `OptionIndex`=7);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45410, `VerifiedBuild`=27843 WHERE (`MenuId`=401 AND `OptionIndex`=6);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45406, `VerifiedBuild`=27843 WHERE (`MenuId`=401 AND `OptionIndex`=5);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45405, `VerifiedBuild`=27843 WHERE (`MenuId`=401 AND `OptionIndex`=4);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=48028, `VerifiedBuild`=27843 WHERE (`MenuId`=401 AND `OptionIndex`=3);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45404, `VerifiedBuild`=27843 WHERE (`MenuId`=401 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=50546, `VerifiedBuild`=27843 WHERE (`MenuId`=401 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45409, `VerifiedBuild`=27843 WHERE (`MenuId`=401 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45383, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=15);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45382, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=14);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=129194, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=13);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45381, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=11);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=44629, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=10);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45380, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=9);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45379, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=8);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45378, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=7);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45376, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=6);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=78584, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=5);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=44627, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=4);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=61849, `VerifiedBuild`=27843 WHERE (`MenuId`=401 AND `OptionIndex`=9);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45408, `VerifiedBuild`=27843 WHERE (`MenuId`=401 AND `OptionIndex`=8);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45407, `VerifiedBuild`=27843 WHERE (`MenuId`=401 AND `OptionIndex`=7);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45410, `VerifiedBuild`=27843 WHERE (`MenuId`=401 AND `OptionIndex`=6);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45406, `VerifiedBuild`=27843 WHERE (`MenuId`=401 AND `OptionIndex`=5);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45405, `VerifiedBuild`=27843 WHERE (`MenuId`=401 AND `OptionIndex`=4);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=48028, `VerifiedBuild`=27843 WHERE (`MenuId`=401 AND `OptionIndex`=3);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45404, `VerifiedBuild`=27843 WHERE (`MenuId`=401 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=50546, `VerifiedBuild`=27843 WHERE (`MenuId`=401 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45409, `VerifiedBuild`=27843 WHERE (`MenuId`=401 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45383, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=15);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45382, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=14);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=129194, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=13);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45381, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=11);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=44629, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=10);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45380, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=9);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45379, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=8);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45378, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=7);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45376, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=6);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=78584, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=5);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=44627, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=4);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=61849, `VerifiedBuild`=27843 WHERE (`MenuId`=401 AND `OptionIndex`=9);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45408, `VerifiedBuild`=27843 WHERE (`MenuId`=401 AND `OptionIndex`=8);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45407, `VerifiedBuild`=27843 WHERE (`MenuId`=401 AND `OptionIndex`=7);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45410, `VerifiedBuild`=27843 WHERE (`MenuId`=401 AND `OptionIndex`=6);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45406, `VerifiedBuild`=27843 WHERE (`MenuId`=401 AND `OptionIndex`=5);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45405, `VerifiedBuild`=27843 WHERE (`MenuId`=401 AND `OptionIndex`=4);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=48028, `VerifiedBuild`=27843 WHERE (`MenuId`=401 AND `OptionIndex`=3);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45404, `VerifiedBuild`=27843 WHERE (`MenuId`=401 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=50546, `VerifiedBuild`=27843 WHERE (`MenuId`=401 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45409, `VerifiedBuild`=27843 WHERE (`MenuId`=401 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45383, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=15);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45382, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=14);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=129194, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=13);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45381, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=11);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=44629, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=10);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45380, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=9);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45379, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=8);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45378, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=7);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45376, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=6);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=78584, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=5);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=44627, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=4);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=61849, `VerifiedBuild`=27843 WHERE (`MenuId`=401 AND `OptionIndex`=9);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45408, `VerifiedBuild`=27843 WHERE (`MenuId`=401 AND `OptionIndex`=8);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45407, `VerifiedBuild`=27843 WHERE (`MenuId`=401 AND `OptionIndex`=7);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45410, `VerifiedBuild`=27843 WHERE (`MenuId`=401 AND `OptionIndex`=6);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45406, `VerifiedBuild`=27843 WHERE (`MenuId`=401 AND `OptionIndex`=5);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45405, `VerifiedBuild`=27843 WHERE (`MenuId`=401 AND `OptionIndex`=4);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=48028, `VerifiedBuild`=27843 WHERE (`MenuId`=401 AND `OptionIndex`=3);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45404, `VerifiedBuild`=27843 WHERE (`MenuId`=401 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=50546, `VerifiedBuild`=27843 WHERE (`MenuId`=401 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45409, `VerifiedBuild`=27843 WHERE (`MenuId`=401 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45383, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=15);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45382, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=14);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=129194, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=13);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45381, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=11);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=44629, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=10);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45380, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=9);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45379, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=8);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45378, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=7);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45376, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=6);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=78584, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=5);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=44627, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=4);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=61849, `VerifiedBuild`=27843 WHERE (`MenuId`=401 AND `OptionIndex`=9);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45408, `VerifiedBuild`=27843 WHERE (`MenuId`=401 AND `OptionIndex`=8);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45407, `VerifiedBuild`=27843 WHERE (`MenuId`=401 AND `OptionIndex`=7);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45410, `VerifiedBuild`=27843 WHERE (`MenuId`=401 AND `OptionIndex`=6);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45406, `VerifiedBuild`=27843 WHERE (`MenuId`=401 AND `OptionIndex`=5);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45405, `VerifiedBuild`=27843 WHERE (`MenuId`=401 AND `OptionIndex`=4);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=48028, `VerifiedBuild`=27843 WHERE (`MenuId`=401 AND `OptionIndex`=3);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45404, `VerifiedBuild`=27843 WHERE (`MenuId`=401 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=50546, `VerifiedBuild`=27843 WHERE (`MenuId`=401 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45409, `VerifiedBuild`=27843 WHERE (`MenuId`=401 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45383, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=15);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45382, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=14);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=129194, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=13);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45381, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=11);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=44629, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=10);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45380, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=9);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45379, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=8);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45378, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=7);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45376, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=6);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=78584, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=5);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=44627, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=4);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=61849, `VerifiedBuild`=27843 WHERE (`MenuId`=401 AND `OptionIndex`=9);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45408, `VerifiedBuild`=27843 WHERE (`MenuId`=401 AND `OptionIndex`=8);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45407, `VerifiedBuild`=27843 WHERE (`MenuId`=401 AND `OptionIndex`=7);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45410, `VerifiedBuild`=27843 WHERE (`MenuId`=401 AND `OptionIndex`=6);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45406, `VerifiedBuild`=27843 WHERE (`MenuId`=401 AND `OptionIndex`=5);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45405, `VerifiedBuild`=27843 WHERE (`MenuId`=401 AND `OptionIndex`=4);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=48028, `VerifiedBuild`=27843 WHERE (`MenuId`=401 AND `OptionIndex`=3);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45404, `VerifiedBuild`=27843 WHERE (`MenuId`=401 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=50546, `VerifiedBuild`=27843 WHERE (`MenuId`=401 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45409, `VerifiedBuild`=27843 WHERE (`MenuId`=401 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45383, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=15);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45382, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=14);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=129194, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=13);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45381, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=11);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=44629, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=10);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45380, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=9);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45379, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=8);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45378, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=7);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45376, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=6);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=78584, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=5);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=44627, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=4);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=61849, `VerifiedBuild`=27843 WHERE (`MenuId`=401 AND `OptionIndex`=9);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45408, `VerifiedBuild`=27843 WHERE (`MenuId`=401 AND `OptionIndex`=8);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45407, `VerifiedBuild`=27843 WHERE (`MenuId`=401 AND `OptionIndex`=7);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45410, `VerifiedBuild`=27843 WHERE (`MenuId`=401 AND `OptionIndex`=6);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45406, `VerifiedBuild`=27843 WHERE (`MenuId`=401 AND `OptionIndex`=5);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45405, `VerifiedBuild`=27843 WHERE (`MenuId`=401 AND `OptionIndex`=4);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=48028, `VerifiedBuild`=27843 WHERE (`MenuId`=401 AND `OptionIndex`=3);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45404, `VerifiedBuild`=27843 WHERE (`MenuId`=401 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=50546, `VerifiedBuild`=27843 WHERE (`MenuId`=401 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45409, `VerifiedBuild`=27843 WHERE (`MenuId`=401 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45383, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=15);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45382, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=14);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=129194, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=13);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45381, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=11);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=44629, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=10);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45380, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=9);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45379, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=8);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45378, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=7);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45376, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=6);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=78584, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=5);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=44627, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=4);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45383, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=15);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45382, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=14);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=129194, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=13);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45381, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=11);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=44629, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=10);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45380, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=9);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45379, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=8);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45378, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=7);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45376, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=6);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=78584, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=5);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=44627, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=4);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45383, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=15);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45382, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=14);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=129194, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=13);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45381, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=11);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=44629, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=10);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45380, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=9);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45379, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=8);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45378, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=7);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45376, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=6);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=78584, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=5);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=44627, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=4);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45383, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=15);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45382, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=14);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=129194, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=13);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45381, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=11);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=44629, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=10);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45380, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=9);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45379, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=8);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45378, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=7);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45376, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=6);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=78584, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=5);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=44627, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=4);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45383, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=15);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45382, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=14);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=129194, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=13);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45381, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=11);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=44629, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=10);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45380, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=9);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45379, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=8);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45378, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=7);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45376, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=6);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=78584, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=5);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=44627, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=4);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45383, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=15);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45382, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=14);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=129194, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=13);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45381, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=11);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=44629, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=10);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45380, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=9);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45379, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=8);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45378, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=7);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45376, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=6);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=78584, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=5);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=44627, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=4);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45383, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=15);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45382, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=14);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=129194, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=13);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45381, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=11);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=44629, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=10);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45380, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=9);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45379, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=8);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45378, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=7);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45376, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=6);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=78584, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=5);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=44627, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=4);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45383, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=15);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45382, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=14);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=129194, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=13);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45381, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=11);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=44629, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=10);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45380, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=9);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45379, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=8);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45378, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=7);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45376, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=6);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=78584, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=5);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=44627, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=4);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45383, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=15);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45382, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=14);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=129194, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=13);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45381, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=11);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=44629, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=10);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45380, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=9);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45379, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=8);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45378, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=7);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45376, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=6);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=78584, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=5);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=44627, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=4);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45383, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=15);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45382, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=14);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=129194, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=13);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45381, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=11);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=44629, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=10);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45380, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=9);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45379, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=8);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45378, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=7);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45376, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=6);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=78584, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=5);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=44627, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=4);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45383, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=15);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45382, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=14);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=129194, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=13);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45381, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=11);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=44629, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=10);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45380, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=9);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45379, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=8);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45378, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=7);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45376, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=6);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=78584, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=5);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=44627, `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=4);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=8097, `VerifiedBuild`=27602 WHERE (`MenuId`=342 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=14967, `VerifiedBuild`=27377 WHERE (`MenuId`=21043 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=14967, `VerifiedBuild`=27377 WHERE (`MenuId`=21043 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=8097, `VerifiedBuild`=27377 WHERE (`MenuId`=10362 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=8097, `VerifiedBuild`=27377 WHERE (`MenuId`=10362 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=8097, `VerifiedBuild`=27377 WHERE (`MenuId`=10667 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=8097, `VerifiedBuild`=27377 WHERE (`MenuId`=9868 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=8097, `VerifiedBuild`=27377 WHERE (`MenuId`=9868 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=8097, `VerifiedBuild`=27377 WHERE (`MenuId`=9868 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=8097, `VerifiedBuild`=27366 WHERE (`MenuId`=9868 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=8097, `VerifiedBuild`=27366 WHERE (`MenuId`=9868 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=8097, `VerifiedBuild`=27366 WHERE (`MenuId`=9868 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=46613, `VerifiedBuild`=27326 WHERE (`MenuId`=12133 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=46613, `VerifiedBuild`=27326 WHERE (`MenuId`=12133 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=46129, `VerifiedBuild`=27326 WHERE (`MenuId`=12083 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45926, `VerifiedBuild`=27326 WHERE (`MenuId`=12059 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45926, `VerifiedBuild`=27326 WHERE (`MenuId`=12059 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=8097, `VerifiedBuild`=27326 WHERE (`MenuId`=342 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=8097, `VerifiedBuild`=27326 WHERE (`MenuId`=342 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=36926, `VerifiedBuild`=27326 WHERE (`MenuId`=12253 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=36925, `VerifiedBuild`=27326 WHERE (`MenuId`=12253 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=36926, `VerifiedBuild`=27326 WHERE (`MenuId`=12253 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=36925, `VerifiedBuild`=27326 WHERE (`MenuId`=12253 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=47907, `VerifiedBuild`=27326 WHERE (`MenuId`=12303 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=36926, `VerifiedBuild`=27326 WHERE (`MenuId`=12253 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=36925, `VerifiedBuild`=27326 WHERE (`MenuId`=12253 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=36926, `VerifiedBuild`=27326 WHERE (`MenuId`=12253 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=36925, `VerifiedBuild`=27326 WHERE (`MenuId`=12253 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=36926, `VerifiedBuild`=27326 WHERE (`MenuId`=12253 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=36925, `VerifiedBuild`=27326 WHERE (`MenuId`=12253 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=36926, `VerifiedBuild`=27326 WHERE (`MenuId`=12253 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=36925, `VerifiedBuild`=27326 WHERE (`MenuId`=12253 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=47907, `VerifiedBuild`=27326 WHERE (`MenuId`=12303 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=36926, `VerifiedBuild`=27326 WHERE (`MenuId`=12253 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=36925, `VerifiedBuild`=27326 WHERE (`MenuId`=12253 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=36926, `VerifiedBuild`=27326 WHERE (`MenuId`=12253 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=36925, `VerifiedBuild`=27326 WHERE (`MenuId`=12253 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=36926, `VerifiedBuild`=27326 WHERE (`MenuId`=12253 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=36925, `VerifiedBuild`=27326 WHERE (`MenuId`=12253 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=36926, `VerifiedBuild`=27326 WHERE (`MenuId`=12253 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=36925, `VerifiedBuild`=27326 WHERE (`MenuId`=12253 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=36926, `VerifiedBuild`=27326 WHERE (`MenuId`=12253 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=36925, `VerifiedBuild`=27326 WHERE (`MenuId`=12253 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=36926, `VerifiedBuild`=27326 WHERE (`MenuId`=12253 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=36925, `VerifiedBuild`=27326 WHERE (`MenuId`=12253 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=36926, `VerifiedBuild`=27326 WHERE (`MenuId`=12253 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=36925, `VerifiedBuild`=27326 WHERE (`MenuId`=12253 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=36926, `VerifiedBuild`=27326 WHERE (`MenuId`=12253 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=36925, `VerifiedBuild`=27326 WHERE (`MenuId`=12253 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=36926, `VerifiedBuild`=27326 WHERE (`MenuId`=12253 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=36925, `VerifiedBuild`=27326 WHERE (`MenuId`=12253 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=36926, `VerifiedBuild`=27326 WHERE (`MenuId`=12253 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=36925, `VerifiedBuild`=27326 WHERE (`MenuId`=12253 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=36926, `VerifiedBuild`=27326 WHERE (`MenuId`=12253 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=36925, `VerifiedBuild`=27326 WHERE (`MenuId`=12253 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=36926, `VerifiedBuild`=27326 WHERE (`MenuId`=12253 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=36925, `VerifiedBuild`=27326 WHERE (`MenuId`=12253 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=36926, `VerifiedBuild`=27326 WHERE (`MenuId`=12253 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=36925, `VerifiedBuild`=27326 WHERE (`MenuId`=12253 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=36926, `VerifiedBuild`=27326 WHERE (`MenuId`=12253 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=36925, `VerifiedBuild`=27326 WHERE (`MenuId`=12253 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=36926, `VerifiedBuild`=27326 WHERE (`MenuId`=12253 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=36925, `VerifiedBuild`=27326 WHERE (`MenuId`=12253 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=36926, `VerifiedBuild`=27326 WHERE (`MenuId`=12253 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=36925, `VerifiedBuild`=27326 WHERE (`MenuId`=12253 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=47907, `VerifiedBuild`=27326 WHERE (`MenuId`=12303 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=49254, `VerifiedBuild`=27326 WHERE (`MenuId`=12480 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=49254, `VerifiedBuild`=27326 WHERE (`MenuId`=12480 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=49050, `VerifiedBuild`=27326 WHERE (`MenuId`=12459 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=48886, `VerifiedBuild`=27326 WHERE (`MenuId`=12457 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=48885, `VerifiedBuild`=27326 WHERE (`MenuId`=12457 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=48884, `VerifiedBuild`=27326 WHERE (`MenuId`=12457 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=48883, `VerifiedBuild`=27326 WHERE (`MenuId`=12456 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=48882, `VerifiedBuild`=27326 WHERE (`MenuId`=12456 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=48881, `VerifiedBuild`=27326 WHERE (`MenuId`=12456 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=48880, `VerifiedBuild`=27326 WHERE (`MenuId`=12455 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=48879, `VerifiedBuild`=27326 WHERE (`MenuId`=12455 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=48877, `VerifiedBuild`=27326 WHERE (`MenuId`=12455 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=48889, `VerifiedBuild`=27326 WHERE (`MenuId`=12451 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=48886, `VerifiedBuild`=27326 WHERE (`MenuId`=12457 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=48885, `VerifiedBuild`=27326 WHERE (`MenuId`=12457 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=48884, `VerifiedBuild`=27326 WHERE (`MenuId`=12457 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=48883, `VerifiedBuild`=27326 WHERE (`MenuId`=12456 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=48882, `VerifiedBuild`=27326 WHERE (`MenuId`=12456 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=48881, `VerifiedBuild`=27326 WHERE (`MenuId`=12456 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=48880, `VerifiedBuild`=27326 WHERE (`MenuId`=12455 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=48879, `VerifiedBuild`=27326 WHERE (`MenuId`=12455 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=48877, `VerifiedBuild`=27326 WHERE (`MenuId`=12455 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=48889, `VerifiedBuild`=27326 WHERE (`MenuId`=12451 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=48886, `VerifiedBuild`=27326 WHERE (`MenuId`=12457 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=48885, `VerifiedBuild`=27326 WHERE (`MenuId`=12457 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=48884, `VerifiedBuild`=27326 WHERE (`MenuId`=12457 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=48883, `VerifiedBuild`=27326 WHERE (`MenuId`=12456 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=48882, `VerifiedBuild`=27326 WHERE (`MenuId`=12456 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=48881, `VerifiedBuild`=27326 WHERE (`MenuId`=12456 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=48880, `VerifiedBuild`=27326 WHERE (`MenuId`=12455 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=48879, `VerifiedBuild`=27326 WHERE (`MenuId`=12455 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=48877, `VerifiedBuild`=27326 WHERE (`MenuId`=12455 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=48889, `VerifiedBuild`=27326 WHERE (`MenuId`=12451 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=48886, `VerifiedBuild`=27326 WHERE (`MenuId`=12457 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=48885, `VerifiedBuild`=27326 WHERE (`MenuId`=12457 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=48884, `VerifiedBuild`=27326 WHERE (`MenuId`=12457 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=48883, `VerifiedBuild`=27326 WHERE (`MenuId`=12456 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=48882, `VerifiedBuild`=27326 WHERE (`MenuId`=12456 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=48881, `VerifiedBuild`=27326 WHERE (`MenuId`=12456 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=48880, `VerifiedBuild`=27326 WHERE (`MenuId`=12455 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=48879, `VerifiedBuild`=27326 WHERE (`MenuId`=12455 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=48877, `VerifiedBuild`=27326 WHERE (`MenuId`=12455 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=48889, `VerifiedBuild`=27326 WHERE (`MenuId`=12451 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=48883, `VerifiedBuild`=27326 WHERE (`MenuId`=12456 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=48882, `VerifiedBuild`=27326 WHERE (`MenuId`=12456 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=48881, `VerifiedBuild`=27326 WHERE (`MenuId`=12456 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=48880, `VerifiedBuild`=27326 WHERE (`MenuId`=12455 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=48879, `VerifiedBuild`=27326 WHERE (`MenuId`=12455 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=48877, `VerifiedBuild`=27326 WHERE (`MenuId`=12455 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=48889, `VerifiedBuild`=27326 WHERE (`MenuId`=12451 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=48883, `VerifiedBuild`=27326 WHERE (`MenuId`=12456 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=48882, `VerifiedBuild`=27326 WHERE (`MenuId`=12456 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=48881, `VerifiedBuild`=27326 WHERE (`MenuId`=12456 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=48880, `VerifiedBuild`=27326 WHERE (`MenuId`=12455 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=48879, `VerifiedBuild`=27326 WHERE (`MenuId`=12455 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=48877, `VerifiedBuild`=27326 WHERE (`MenuId`=12455 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=48889, `VerifiedBuild`=27326 WHERE (`MenuId`=12451 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=48883, `VerifiedBuild`=27326 WHERE (`MenuId`=12456 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=48882, `VerifiedBuild`=27326 WHERE (`MenuId`=12456 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=48881, `VerifiedBuild`=27326 WHERE (`MenuId`=12456 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=48880, `VerifiedBuild`=27326 WHERE (`MenuId`=12455 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=48879, `VerifiedBuild`=27326 WHERE (`MenuId`=12455 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=48877, `VerifiedBuild`=27326 WHERE (`MenuId`=12455 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=48889, `VerifiedBuild`=27326 WHERE (`MenuId`=12451 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=48880, `VerifiedBuild`=27326 WHERE (`MenuId`=12455 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=48879, `VerifiedBuild`=27326 WHERE (`MenuId`=12455 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=48877, `VerifiedBuild`=27326 WHERE (`MenuId`=12455 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=48889, `VerifiedBuild`=27326 WHERE (`MenuId`=12451 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=48889, `VerifiedBuild`=27326 WHERE (`MenuId`=12451 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=124289, `VerifiedBuild`=27326 WHERE (`MenuId`=12130 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=48459, `VerifiedBuild`=27326 WHERE (`MenuId`=12409 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=48459, `VerifiedBuild`=27326 WHERE (`MenuId`=12409 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=2822, `VerifiedBuild`=27326 WHERE (`MenuId`=12003 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=48787, `VerifiedBuild`=27291 WHERE (`MenuId`=12441 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=48787, `VerifiedBuild`=27291 WHERE (`MenuId`=12441 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=2822, `VerifiedBuild`=27291 WHERE (`MenuId`=12499 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=49462, `VerifiedBuild`=27291 WHERE (`MenuId`=12499 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=2822, `VerifiedBuild`=27291 WHERE (`MenuId`=12499 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=49462, `VerifiedBuild`=27291 WHERE (`MenuId`=12499 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=48397, `VerifiedBuild`=27291 WHERE (`MenuId`=12403 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=48155, `VerifiedBuild`=27291 WHERE (`MenuId`=12354 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=47985, `VerifiedBuild`=27291 WHERE (`MenuId`=12315 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=47983, `VerifiedBuild`=27291 WHERE (`MenuId`=12314 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=47746, `VerifiedBuild`=27291 WHERE (`MenuId`=12286 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=47744, `VerifiedBuild`=27291 WHERE (`MenuId`=12285 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=47742, `VerifiedBuild`=27291 WHERE (`MenuId`=12284 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=47753, `VerifiedBuild`=27291 WHERE (`MenuId`=12290 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=47751, `VerifiedBuild`=27291 WHERE (`MenuId`=12289 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=47749, `VerifiedBuild`=27291 WHERE (`MenuId`=12288 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=47990, `VerifiedBuild`=27291 WHERE (`MenuId`=12318 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=47988, `VerifiedBuild`=27291 WHERE (`MenuId`=12317 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=47749, `VerifiedBuild`=27291 WHERE (`MenuId`=12288 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=47753, `VerifiedBuild`=27291 WHERE (`MenuId`=12290 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=47751, `VerifiedBuild`=27291 WHERE (`MenuId`=12289 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=47749, `VerifiedBuild`=27291 WHERE (`MenuId`=12288 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=47988, `VerifiedBuild`=27291 WHERE (`MenuId`=12317 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=47749, `VerifiedBuild`=27291 WHERE (`MenuId`=12288 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=47983, `VerifiedBuild`=27291 WHERE (`MenuId`=12314 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=47988, `VerifiedBuild`=27291 WHERE (`MenuId`=12317 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=47742, `VerifiedBuild`=27291 WHERE (`MenuId`=12284 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=47450, `VerifiedBuild`=27291 WHERE (`MenuId`=12238 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=47450, `VerifiedBuild`=27291 WHERE (`MenuId`=12238 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=47450, `VerifiedBuild`=27291 WHERE (`MenuId`=12238 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=47450, `VerifiedBuild`=27291 WHERE (`MenuId`=12238 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=47450, `VerifiedBuild`=27291 WHERE (`MenuId`=12238 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=47450, `VerifiedBuild`=27291 WHERE (`MenuId`=12238 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=47450, `VerifiedBuild`=27291 WHERE (`MenuId`=12238 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=47450, `VerifiedBuild`=27291 WHERE (`MenuId`=12238 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=47450, `VerifiedBuild`=27291 WHERE (`MenuId`=12238 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=47450, `VerifiedBuild`=27291 WHERE (`MenuId`=12238 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=47450, `VerifiedBuild`=27291 WHERE (`MenuId`=12238 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=47450, `VerifiedBuild`=27291 WHERE (`MenuId`=12238 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=47450, `VerifiedBuild`=27291 WHERE (`MenuId`=12238 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=47450, `VerifiedBuild`=27291 WHERE (`MenuId`=12238 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=47450, `VerifiedBuild`=27291 WHERE (`MenuId`=12238 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=47450, `VerifiedBuild`=27291 WHERE (`MenuId`=12238 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=47450, `VerifiedBuild`=27291 WHERE (`MenuId`=12238 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45687, `VerifiedBuild`=27291 WHERE (`MenuId`=12038 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42004, `VerifiedBuild`=27291 WHERE (`MenuId`=11592 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42004, `VerifiedBuild`=27291 WHERE (`MenuId`=11591 AND `OptionIndex`=3);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42000, `VerifiedBuild`=27291 WHERE (`MenuId`=11591 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41999, `VerifiedBuild`=27291 WHERE (`MenuId`=11591 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41998, `VerifiedBuild`=27291 WHERE (`MenuId`=11591 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42004, `VerifiedBuild`=27291 WHERE (`MenuId`=11590 AND `OptionIndex`=3);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42000, `VerifiedBuild`=27291 WHERE (`MenuId`=11590 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41999, `VerifiedBuild`=27291 WHERE (`MenuId`=11590 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41998, `VerifiedBuild`=27291 WHERE (`MenuId`=11590 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42004, `VerifiedBuild`=27291 WHERE (`MenuId`=11589 AND `OptionIndex`=3);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42000, `VerifiedBuild`=27291 WHERE (`MenuId`=11589 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41999, `VerifiedBuild`=27291 WHERE (`MenuId`=11589 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41998, `VerifiedBuild`=27291 WHERE (`MenuId`=11589 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42004, `VerifiedBuild`=27291 WHERE (`MenuId`=11588 AND `OptionIndex`=3);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42000, `VerifiedBuild`=27291 WHERE (`MenuId`=11588 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41999, `VerifiedBuild`=27291 WHERE (`MenuId`=11588 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41998, `VerifiedBuild`=27291 WHERE (`MenuId`=11588 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42000, `VerifiedBuild`=27291 WHERE (`MenuId`=11593 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41999, `VerifiedBuild`=27291 WHERE (`MenuId`=11593 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41998, `VerifiedBuild`=27291 WHERE (`MenuId`=11593 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42002, `VerifiedBuild`=27291 WHERE (`MenuId`=11586 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42004, `VerifiedBuild`=27291 WHERE (`MenuId`=11592 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42004, `VerifiedBuild`=27291 WHERE (`MenuId`=11591 AND `OptionIndex`=3);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42000, `VerifiedBuild`=27291 WHERE (`MenuId`=11591 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41999, `VerifiedBuild`=27291 WHERE (`MenuId`=11591 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41998, `VerifiedBuild`=27291 WHERE (`MenuId`=11591 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42004, `VerifiedBuild`=27291 WHERE (`MenuId`=11590 AND `OptionIndex`=3);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42000, `VerifiedBuild`=27291 WHERE (`MenuId`=11590 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41999, `VerifiedBuild`=27291 WHERE (`MenuId`=11590 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41998, `VerifiedBuild`=27291 WHERE (`MenuId`=11590 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42004, `VerifiedBuild`=27291 WHERE (`MenuId`=11589 AND `OptionIndex`=3);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42000, `VerifiedBuild`=27291 WHERE (`MenuId`=11589 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41999, `VerifiedBuild`=27291 WHERE (`MenuId`=11589 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41998, `VerifiedBuild`=27291 WHERE (`MenuId`=11589 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42004, `VerifiedBuild`=27291 WHERE (`MenuId`=11588 AND `OptionIndex`=3);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42000, `VerifiedBuild`=27291 WHERE (`MenuId`=11588 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41999, `VerifiedBuild`=27291 WHERE (`MenuId`=11588 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41998, `VerifiedBuild`=27291 WHERE (`MenuId`=11588 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42000, `VerifiedBuild`=27291 WHERE (`MenuId`=11593 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41999, `VerifiedBuild`=27291 WHERE (`MenuId`=11593 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41998, `VerifiedBuild`=27291 WHERE (`MenuId`=11593 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42002, `VerifiedBuild`=27291 WHERE (`MenuId`=11586 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42004, `VerifiedBuild`=27291 WHERE (`MenuId`=11592 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42004, `VerifiedBuild`=27291 WHERE (`MenuId`=11591 AND `OptionIndex`=3);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42000, `VerifiedBuild`=27291 WHERE (`MenuId`=11591 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41999, `VerifiedBuild`=27291 WHERE (`MenuId`=11591 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41998, `VerifiedBuild`=27291 WHERE (`MenuId`=11591 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42004, `VerifiedBuild`=27291 WHERE (`MenuId`=11590 AND `OptionIndex`=3);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42000, `VerifiedBuild`=27291 WHERE (`MenuId`=11590 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41999, `VerifiedBuild`=27291 WHERE (`MenuId`=11590 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41998, `VerifiedBuild`=27291 WHERE (`MenuId`=11590 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42004, `VerifiedBuild`=27291 WHERE (`MenuId`=11589 AND `OptionIndex`=3);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42000, `VerifiedBuild`=27291 WHERE (`MenuId`=11589 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41999, `VerifiedBuild`=27291 WHERE (`MenuId`=11589 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41998, `VerifiedBuild`=27291 WHERE (`MenuId`=11589 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42004, `VerifiedBuild`=27291 WHERE (`MenuId`=11588 AND `OptionIndex`=3);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42000, `VerifiedBuild`=27291 WHERE (`MenuId`=11588 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41999, `VerifiedBuild`=27291 WHERE (`MenuId`=11588 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41998, `VerifiedBuild`=27291 WHERE (`MenuId`=11588 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42000, `VerifiedBuild`=27291 WHERE (`MenuId`=11593 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41999, `VerifiedBuild`=27291 WHERE (`MenuId`=11593 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41998, `VerifiedBuild`=27291 WHERE (`MenuId`=11593 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42002, `VerifiedBuild`=27291 WHERE (`MenuId`=11586 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42004, `VerifiedBuild`=27291 WHERE (`MenuId`=11592 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42004, `VerifiedBuild`=27291 WHERE (`MenuId`=11591 AND `OptionIndex`=3);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42000, `VerifiedBuild`=27291 WHERE (`MenuId`=11591 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41999, `VerifiedBuild`=27291 WHERE (`MenuId`=11591 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41998, `VerifiedBuild`=27291 WHERE (`MenuId`=11591 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42004, `VerifiedBuild`=27291 WHERE (`MenuId`=11590 AND `OptionIndex`=3);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42000, `VerifiedBuild`=27291 WHERE (`MenuId`=11590 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41999, `VerifiedBuild`=27291 WHERE (`MenuId`=11590 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41998, `VerifiedBuild`=27291 WHERE (`MenuId`=11590 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42004, `VerifiedBuild`=27291 WHERE (`MenuId`=11589 AND `OptionIndex`=3);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42000, `VerifiedBuild`=27291 WHERE (`MenuId`=11589 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41999, `VerifiedBuild`=27291 WHERE (`MenuId`=11589 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41998, `VerifiedBuild`=27291 WHERE (`MenuId`=11589 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42004, `VerifiedBuild`=27291 WHERE (`MenuId`=11588 AND `OptionIndex`=3);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42000, `VerifiedBuild`=27291 WHERE (`MenuId`=11588 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41999, `VerifiedBuild`=27291 WHERE (`MenuId`=11588 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41998, `VerifiedBuild`=27291 WHERE (`MenuId`=11588 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42000, `VerifiedBuild`=27291 WHERE (`MenuId`=11593 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41999, `VerifiedBuild`=27291 WHERE (`MenuId`=11593 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41998, `VerifiedBuild`=27291 WHERE (`MenuId`=11593 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42002, `VerifiedBuild`=27291 WHERE (`MenuId`=11586 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42004, `VerifiedBuild`=27291 WHERE (`MenuId`=11592 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42004, `VerifiedBuild`=27291 WHERE (`MenuId`=11591 AND `OptionIndex`=3);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42000, `VerifiedBuild`=27291 WHERE (`MenuId`=11591 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41999, `VerifiedBuild`=27291 WHERE (`MenuId`=11591 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41998, `VerifiedBuild`=27291 WHERE (`MenuId`=11591 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42004, `VerifiedBuild`=27291 WHERE (`MenuId`=11590 AND `OptionIndex`=3);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42000, `VerifiedBuild`=27291 WHERE (`MenuId`=11590 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41999, `VerifiedBuild`=27291 WHERE (`MenuId`=11590 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41998, `VerifiedBuild`=27291 WHERE (`MenuId`=11590 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42004, `VerifiedBuild`=27291 WHERE (`MenuId`=11589 AND `OptionIndex`=3);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42000, `VerifiedBuild`=27291 WHERE (`MenuId`=11589 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41999, `VerifiedBuild`=27291 WHERE (`MenuId`=11589 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41998, `VerifiedBuild`=27291 WHERE (`MenuId`=11589 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42004, `VerifiedBuild`=27291 WHERE (`MenuId`=11588 AND `OptionIndex`=3);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42000, `VerifiedBuild`=27291 WHERE (`MenuId`=11588 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41999, `VerifiedBuild`=27291 WHERE (`MenuId`=11588 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41998, `VerifiedBuild`=27291 WHERE (`MenuId`=11588 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42000, `VerifiedBuild`=27291 WHERE (`MenuId`=11593 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41999, `VerifiedBuild`=27291 WHERE (`MenuId`=11593 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41998, `VerifiedBuild`=27291 WHERE (`MenuId`=11593 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42002, `VerifiedBuild`=27291 WHERE (`MenuId`=11586 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42004, `VerifiedBuild`=27291 WHERE (`MenuId`=11592 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42004, `VerifiedBuild`=27291 WHERE (`MenuId`=11591 AND `OptionIndex`=3);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42000, `VerifiedBuild`=27291 WHERE (`MenuId`=11591 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41999, `VerifiedBuild`=27291 WHERE (`MenuId`=11591 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41998, `VerifiedBuild`=27291 WHERE (`MenuId`=11591 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42004, `VerifiedBuild`=27291 WHERE (`MenuId`=11590 AND `OptionIndex`=3);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42000, `VerifiedBuild`=27291 WHERE (`MenuId`=11590 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41999, `VerifiedBuild`=27291 WHERE (`MenuId`=11590 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41998, `VerifiedBuild`=27291 WHERE (`MenuId`=11590 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42004, `VerifiedBuild`=27291 WHERE (`MenuId`=11589 AND `OptionIndex`=3);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42000, `VerifiedBuild`=27291 WHERE (`MenuId`=11589 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41999, `VerifiedBuild`=27291 WHERE (`MenuId`=11589 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41998, `VerifiedBuild`=27291 WHERE (`MenuId`=11589 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42004, `VerifiedBuild`=27291 WHERE (`MenuId`=11588 AND `OptionIndex`=3);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42000, `VerifiedBuild`=27291 WHERE (`MenuId`=11588 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41999, `VerifiedBuild`=27291 WHERE (`MenuId`=11588 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41998, `VerifiedBuild`=27291 WHERE (`MenuId`=11588 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42000, `VerifiedBuild`=27291 WHERE (`MenuId`=11593 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41999, `VerifiedBuild`=27291 WHERE (`MenuId`=11593 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41998, `VerifiedBuild`=27291 WHERE (`MenuId`=11593 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42002, `VerifiedBuild`=27291 WHERE (`MenuId`=11586 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42004, `VerifiedBuild`=27291 WHERE (`MenuId`=11592 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42004, `VerifiedBuild`=27291 WHERE (`MenuId`=11591 AND `OptionIndex`=3);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42000, `VerifiedBuild`=27291 WHERE (`MenuId`=11591 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41999, `VerifiedBuild`=27291 WHERE (`MenuId`=11591 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41998, `VerifiedBuild`=27291 WHERE (`MenuId`=11591 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42004, `VerifiedBuild`=27291 WHERE (`MenuId`=11590 AND `OptionIndex`=3);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42000, `VerifiedBuild`=27291 WHERE (`MenuId`=11590 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41999, `VerifiedBuild`=27291 WHERE (`MenuId`=11590 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41998, `VerifiedBuild`=27291 WHERE (`MenuId`=11590 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42004, `VerifiedBuild`=27291 WHERE (`MenuId`=11589 AND `OptionIndex`=3);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42000, `VerifiedBuild`=27291 WHERE (`MenuId`=11589 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41999, `VerifiedBuild`=27291 WHERE (`MenuId`=11589 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41998, `VerifiedBuild`=27291 WHERE (`MenuId`=11589 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42004, `VerifiedBuild`=27291 WHERE (`MenuId`=11588 AND `OptionIndex`=3);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42000, `VerifiedBuild`=27291 WHERE (`MenuId`=11588 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41999, `VerifiedBuild`=27291 WHERE (`MenuId`=11588 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41998, `VerifiedBuild`=27291 WHERE (`MenuId`=11588 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42000, `VerifiedBuild`=27291 WHERE (`MenuId`=11593 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41999, `VerifiedBuild`=27291 WHERE (`MenuId`=11593 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41998, `VerifiedBuild`=27291 WHERE (`MenuId`=11593 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42002, `VerifiedBuild`=27291 WHERE (`MenuId`=11586 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42004, `VerifiedBuild`=27291 WHERE (`MenuId`=11592 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42004, `VerifiedBuild`=27291 WHERE (`MenuId`=11591 AND `OptionIndex`=3);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42000, `VerifiedBuild`=27291 WHERE (`MenuId`=11591 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41999, `VerifiedBuild`=27291 WHERE (`MenuId`=11591 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41998, `VerifiedBuild`=27291 WHERE (`MenuId`=11591 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42004, `VerifiedBuild`=27291 WHERE (`MenuId`=11590 AND `OptionIndex`=3);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42000, `VerifiedBuild`=27291 WHERE (`MenuId`=11590 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41999, `VerifiedBuild`=27291 WHERE (`MenuId`=11590 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41998, `VerifiedBuild`=27291 WHERE (`MenuId`=11590 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42004, `VerifiedBuild`=27291 WHERE (`MenuId`=11589 AND `OptionIndex`=3);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42000, `VerifiedBuild`=27291 WHERE (`MenuId`=11589 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41999, `VerifiedBuild`=27291 WHERE (`MenuId`=11589 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41998, `VerifiedBuild`=27291 WHERE (`MenuId`=11589 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42004, `VerifiedBuild`=27291 WHERE (`MenuId`=11588 AND `OptionIndex`=3);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42000, `VerifiedBuild`=27291 WHERE (`MenuId`=11588 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41999, `VerifiedBuild`=27291 WHERE (`MenuId`=11588 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41998, `VerifiedBuild`=27291 WHERE (`MenuId`=11588 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42000, `VerifiedBuild`=27291 WHERE (`MenuId`=11593 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41999, `VerifiedBuild`=27291 WHERE (`MenuId`=11593 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41998, `VerifiedBuild`=27291 WHERE (`MenuId`=11593 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42002, `VerifiedBuild`=27291 WHERE (`MenuId`=11586 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42004, `VerifiedBuild`=27291 WHERE (`MenuId`=11592 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42004, `VerifiedBuild`=27291 WHERE (`MenuId`=11591 AND `OptionIndex`=3);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42000, `VerifiedBuild`=27291 WHERE (`MenuId`=11591 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41999, `VerifiedBuild`=27291 WHERE (`MenuId`=11591 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41998, `VerifiedBuild`=27291 WHERE (`MenuId`=11591 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42004, `VerifiedBuild`=27291 WHERE (`MenuId`=11590 AND `OptionIndex`=3);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42000, `VerifiedBuild`=27291 WHERE (`MenuId`=11590 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41999, `VerifiedBuild`=27291 WHERE (`MenuId`=11590 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41998, `VerifiedBuild`=27291 WHERE (`MenuId`=11590 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42004, `VerifiedBuild`=27291 WHERE (`MenuId`=11589 AND `OptionIndex`=3);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42000, `VerifiedBuild`=27291 WHERE (`MenuId`=11589 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41999, `VerifiedBuild`=27291 WHERE (`MenuId`=11589 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41998, `VerifiedBuild`=27291 WHERE (`MenuId`=11589 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42004, `VerifiedBuild`=27291 WHERE (`MenuId`=11588 AND `OptionIndex`=3);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42000, `VerifiedBuild`=27291 WHERE (`MenuId`=11588 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41999, `VerifiedBuild`=27291 WHERE (`MenuId`=11588 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41998, `VerifiedBuild`=27291 WHERE (`MenuId`=11588 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42000, `VerifiedBuild`=27291 WHERE (`MenuId`=11593 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41999, `VerifiedBuild`=27291 WHERE (`MenuId`=11593 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41998, `VerifiedBuild`=27291 WHERE (`MenuId`=11593 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42002, `VerifiedBuild`=27291 WHERE (`MenuId`=11586 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42004, `VerifiedBuild`=27291 WHERE (`MenuId`=11592 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42004, `VerifiedBuild`=27291 WHERE (`MenuId`=11591 AND `OptionIndex`=3);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42000, `VerifiedBuild`=27291 WHERE (`MenuId`=11591 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41999, `VerifiedBuild`=27291 WHERE (`MenuId`=11591 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41998, `VerifiedBuild`=27291 WHERE (`MenuId`=11591 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42004, `VerifiedBuild`=27291 WHERE (`MenuId`=11590 AND `OptionIndex`=3);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42000, `VerifiedBuild`=27291 WHERE (`MenuId`=11590 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41999, `VerifiedBuild`=27291 WHERE (`MenuId`=11590 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41998, `VerifiedBuild`=27291 WHERE (`MenuId`=11590 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42004, `VerifiedBuild`=27291 WHERE (`MenuId`=11589 AND `OptionIndex`=3);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42000, `VerifiedBuild`=27291 WHERE (`MenuId`=11589 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41999, `VerifiedBuild`=27291 WHERE (`MenuId`=11589 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41998, `VerifiedBuild`=27291 WHERE (`MenuId`=11589 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42004, `VerifiedBuild`=27291 WHERE (`MenuId`=11588 AND `OptionIndex`=3);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42000, `VerifiedBuild`=27291 WHERE (`MenuId`=11588 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41999, `VerifiedBuild`=27291 WHERE (`MenuId`=11588 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41998, `VerifiedBuild`=27291 WHERE (`MenuId`=11588 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42000, `VerifiedBuild`=27291 WHERE (`MenuId`=11593 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41999, `VerifiedBuild`=27291 WHERE (`MenuId`=11593 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41998, `VerifiedBuild`=27291 WHERE (`MenuId`=11593 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42002, `VerifiedBuild`=27291 WHERE (`MenuId`=11586 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42004, `VerifiedBuild`=27291 WHERE (`MenuId`=11592 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42004, `VerifiedBuild`=27291 WHERE (`MenuId`=11591 AND `OptionIndex`=3);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42000, `VerifiedBuild`=27291 WHERE (`MenuId`=11591 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41999, `VerifiedBuild`=27291 WHERE (`MenuId`=11591 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41998, `VerifiedBuild`=27291 WHERE (`MenuId`=11591 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42004, `VerifiedBuild`=27291 WHERE (`MenuId`=11590 AND `OptionIndex`=3);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42000, `VerifiedBuild`=27291 WHERE (`MenuId`=11590 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41999, `VerifiedBuild`=27291 WHERE (`MenuId`=11590 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41998, `VerifiedBuild`=27291 WHERE (`MenuId`=11590 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42004, `VerifiedBuild`=27291 WHERE (`MenuId`=11589 AND `OptionIndex`=3);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42000, `VerifiedBuild`=27291 WHERE (`MenuId`=11589 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41999, `VerifiedBuild`=27291 WHERE (`MenuId`=11589 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41998, `VerifiedBuild`=27291 WHERE (`MenuId`=11589 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42004, `VerifiedBuild`=27291 WHERE (`MenuId`=11588 AND `OptionIndex`=3);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42000, `VerifiedBuild`=27291 WHERE (`MenuId`=11588 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41999, `VerifiedBuild`=27291 WHERE (`MenuId`=11588 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41998, `VerifiedBuild`=27291 WHERE (`MenuId`=11588 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42000, `VerifiedBuild`=27291 WHERE (`MenuId`=11593 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41999, `VerifiedBuild`=27291 WHERE (`MenuId`=11593 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41998, `VerifiedBuild`=27291 WHERE (`MenuId`=11593 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42002, `VerifiedBuild`=27291 WHERE (`MenuId`=11586 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42004, `VerifiedBuild`=27291 WHERE (`MenuId`=11592 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42004, `VerifiedBuild`=27291 WHERE (`MenuId`=11591 AND `OptionIndex`=3);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42000, `VerifiedBuild`=27291 WHERE (`MenuId`=11591 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41999, `VerifiedBuild`=27291 WHERE (`MenuId`=11591 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41998, `VerifiedBuild`=27291 WHERE (`MenuId`=11591 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42004, `VerifiedBuild`=27291 WHERE (`MenuId`=11590 AND `OptionIndex`=3);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42000, `VerifiedBuild`=27291 WHERE (`MenuId`=11590 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41999, `VerifiedBuild`=27291 WHERE (`MenuId`=11590 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41998, `VerifiedBuild`=27291 WHERE (`MenuId`=11590 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42004, `VerifiedBuild`=27291 WHERE (`MenuId`=11589 AND `OptionIndex`=3);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42000, `VerifiedBuild`=27291 WHERE (`MenuId`=11589 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41999, `VerifiedBuild`=27291 WHERE (`MenuId`=11589 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41998, `VerifiedBuild`=27291 WHERE (`MenuId`=11589 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42004, `VerifiedBuild`=27291 WHERE (`MenuId`=11588 AND `OptionIndex`=3);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42000, `VerifiedBuild`=27291 WHERE (`MenuId`=11588 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41999, `VerifiedBuild`=27291 WHERE (`MenuId`=11588 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41998, `VerifiedBuild`=27291 WHERE (`MenuId`=11588 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42000, `VerifiedBuild`=27291 WHERE (`MenuId`=11593 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41999, `VerifiedBuild`=27291 WHERE (`MenuId`=11593 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41998, `VerifiedBuild`=27291 WHERE (`MenuId`=11593 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42002, `VerifiedBuild`=27291 WHERE (`MenuId`=11586 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42004, `VerifiedBuild`=27291 WHERE (`MenuId`=11592 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42004, `VerifiedBuild`=27291 WHERE (`MenuId`=11591 AND `OptionIndex`=3);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42000, `VerifiedBuild`=27291 WHERE (`MenuId`=11591 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41999, `VerifiedBuild`=27291 WHERE (`MenuId`=11591 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41998, `VerifiedBuild`=27291 WHERE (`MenuId`=11591 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42004, `VerifiedBuild`=27291 WHERE (`MenuId`=11590 AND `OptionIndex`=3);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42000, `VerifiedBuild`=27291 WHERE (`MenuId`=11590 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41999, `VerifiedBuild`=27291 WHERE (`MenuId`=11590 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41998, `VerifiedBuild`=27291 WHERE (`MenuId`=11590 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42004, `VerifiedBuild`=27291 WHERE (`MenuId`=11589 AND `OptionIndex`=3);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42000, `VerifiedBuild`=27291 WHERE (`MenuId`=11589 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41999, `VerifiedBuild`=27291 WHERE (`MenuId`=11589 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41998, `VerifiedBuild`=27291 WHERE (`MenuId`=11589 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42004, `VerifiedBuild`=27291 WHERE (`MenuId`=11588 AND `OptionIndex`=3);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42000, `VerifiedBuild`=27291 WHERE (`MenuId`=11588 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41999, `VerifiedBuild`=27291 WHERE (`MenuId`=11588 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41998, `VerifiedBuild`=27291 WHERE (`MenuId`=11588 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42000, `VerifiedBuild`=27291 WHERE (`MenuId`=11593 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41999, `VerifiedBuild`=27291 WHERE (`MenuId`=11593 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41998, `VerifiedBuild`=27291 WHERE (`MenuId`=11593 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42002, `VerifiedBuild`=27291 WHERE (`MenuId`=11586 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42004, `VerifiedBuild`=27291 WHERE (`MenuId`=11592 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42004, `VerifiedBuild`=27291 WHERE (`MenuId`=11591 AND `OptionIndex`=3);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42000, `VerifiedBuild`=27291 WHERE (`MenuId`=11591 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41999, `VerifiedBuild`=27291 WHERE (`MenuId`=11591 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41998, `VerifiedBuild`=27291 WHERE (`MenuId`=11591 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42004, `VerifiedBuild`=27291 WHERE (`MenuId`=11590 AND `OptionIndex`=3);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42000, `VerifiedBuild`=27291 WHERE (`MenuId`=11590 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41999, `VerifiedBuild`=27291 WHERE (`MenuId`=11590 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41998, `VerifiedBuild`=27291 WHERE (`MenuId`=11590 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42004, `VerifiedBuild`=27291 WHERE (`MenuId`=11589 AND `OptionIndex`=3);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42000, `VerifiedBuild`=27291 WHERE (`MenuId`=11589 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41999, `VerifiedBuild`=27291 WHERE (`MenuId`=11589 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41998, `VerifiedBuild`=27291 WHERE (`MenuId`=11589 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42004, `VerifiedBuild`=27291 WHERE (`MenuId`=11588 AND `OptionIndex`=3);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42000, `VerifiedBuild`=27291 WHERE (`MenuId`=11588 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41999, `VerifiedBuild`=27291 WHERE (`MenuId`=11588 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41998, `VerifiedBuild`=27291 WHERE (`MenuId`=11588 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42000, `VerifiedBuild`=27291 WHERE (`MenuId`=11593 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41999, `VerifiedBuild`=27291 WHERE (`MenuId`=11593 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41998, `VerifiedBuild`=27291 WHERE (`MenuId`=11593 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42002, `VerifiedBuild`=27291 WHERE (`MenuId`=11586 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42004, `VerifiedBuild`=27291 WHERE (`MenuId`=11592 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42004, `VerifiedBuild`=27291 WHERE (`MenuId`=11591 AND `OptionIndex`=3);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42000, `VerifiedBuild`=27291 WHERE (`MenuId`=11591 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41999, `VerifiedBuild`=27291 WHERE (`MenuId`=11591 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41998, `VerifiedBuild`=27291 WHERE (`MenuId`=11591 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42004, `VerifiedBuild`=27291 WHERE (`MenuId`=11590 AND `OptionIndex`=3);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42000, `VerifiedBuild`=27291 WHERE (`MenuId`=11590 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41999, `VerifiedBuild`=27291 WHERE (`MenuId`=11590 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41998, `VerifiedBuild`=27291 WHERE (`MenuId`=11590 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42004, `VerifiedBuild`=27291 WHERE (`MenuId`=11589 AND `OptionIndex`=3);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42000, `VerifiedBuild`=27291 WHERE (`MenuId`=11589 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41999, `VerifiedBuild`=27291 WHERE (`MenuId`=11589 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41998, `VerifiedBuild`=27291 WHERE (`MenuId`=11589 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42004, `VerifiedBuild`=27291 WHERE (`MenuId`=11588 AND `OptionIndex`=3);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42000, `VerifiedBuild`=27291 WHERE (`MenuId`=11588 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41999, `VerifiedBuild`=27291 WHERE (`MenuId`=11588 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41998, `VerifiedBuild`=27291 WHERE (`MenuId`=11588 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42000, `VerifiedBuild`=27291 WHERE (`MenuId`=11593 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41999, `VerifiedBuild`=27291 WHERE (`MenuId`=11593 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41998, `VerifiedBuild`=27291 WHERE (`MenuId`=11593 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42002, `VerifiedBuild`=27291 WHERE (`MenuId`=11586 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42004, `VerifiedBuild`=27291 WHERE (`MenuId`=11592 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42004, `VerifiedBuild`=27291 WHERE (`MenuId`=11591 AND `OptionIndex`=3);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42000, `VerifiedBuild`=27291 WHERE (`MenuId`=11591 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41999, `VerifiedBuild`=27291 WHERE (`MenuId`=11591 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41998, `VerifiedBuild`=27291 WHERE (`MenuId`=11591 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42004, `VerifiedBuild`=27291 WHERE (`MenuId`=11590 AND `OptionIndex`=3);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42000, `VerifiedBuild`=27291 WHERE (`MenuId`=11590 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41999, `VerifiedBuild`=27291 WHERE (`MenuId`=11590 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41998, `VerifiedBuild`=27291 WHERE (`MenuId`=11590 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42004, `VerifiedBuild`=27291 WHERE (`MenuId`=11589 AND `OptionIndex`=3);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42000, `VerifiedBuild`=27291 WHERE (`MenuId`=11589 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41999, `VerifiedBuild`=27291 WHERE (`MenuId`=11589 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41998, `VerifiedBuild`=27291 WHERE (`MenuId`=11589 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42004, `VerifiedBuild`=27291 WHERE (`MenuId`=11588 AND `OptionIndex`=3);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42000, `VerifiedBuild`=27291 WHERE (`MenuId`=11588 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41999, `VerifiedBuild`=27291 WHERE (`MenuId`=11588 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41998, `VerifiedBuild`=27291 WHERE (`MenuId`=11588 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42000, `VerifiedBuild`=27291 WHERE (`MenuId`=11593 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41999, `VerifiedBuild`=27291 WHERE (`MenuId`=11593 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41998, `VerifiedBuild`=27291 WHERE (`MenuId`=11593 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42002, `VerifiedBuild`=27291 WHERE (`MenuId`=11586 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42000, `VerifiedBuild`=27291 WHERE (`MenuId`=11593 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41999, `VerifiedBuild`=27291 WHERE (`MenuId`=11593 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41998, `VerifiedBuild`=27291 WHERE (`MenuId`=11593 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42002, `VerifiedBuild`=27291 WHERE (`MenuId`=11586 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42004, `VerifiedBuild`=27291 WHERE (`MenuId`=11592 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42004, `VerifiedBuild`=27291 WHERE (`MenuId`=11591 AND `OptionIndex`=3);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42000, `VerifiedBuild`=27291 WHERE (`MenuId`=11591 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41999, `VerifiedBuild`=27291 WHERE (`MenuId`=11591 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41998, `VerifiedBuild`=27291 WHERE (`MenuId`=11591 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42004, `VerifiedBuild`=27291 WHERE (`MenuId`=11590 AND `OptionIndex`=3);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42000, `VerifiedBuild`=27291 WHERE (`MenuId`=11590 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41999, `VerifiedBuild`=27291 WHERE (`MenuId`=11590 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41998, `VerifiedBuild`=27291 WHERE (`MenuId`=11590 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42004, `VerifiedBuild`=27291 WHERE (`MenuId`=11589 AND `OptionIndex`=3);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42000, `VerifiedBuild`=27291 WHERE (`MenuId`=11589 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41999, `VerifiedBuild`=27291 WHERE (`MenuId`=11589 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41998, `VerifiedBuild`=27291 WHERE (`MenuId`=11589 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42004, `VerifiedBuild`=27291 WHERE (`MenuId`=11588 AND `OptionIndex`=3);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42000, `VerifiedBuild`=27291 WHERE (`MenuId`=11588 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41999, `VerifiedBuild`=27291 WHERE (`MenuId`=11588 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41998, `VerifiedBuild`=27291 WHERE (`MenuId`=11588 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42000, `VerifiedBuild`=27291 WHERE (`MenuId`=11593 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41999, `VerifiedBuild`=27291 WHERE (`MenuId`=11593 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41998, `VerifiedBuild`=27291 WHERE (`MenuId`=11593 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42002, `VerifiedBuild`=27291 WHERE (`MenuId`=11586 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42004, `VerifiedBuild`=27291 WHERE (`MenuId`=11592 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42004, `VerifiedBuild`=27291 WHERE (`MenuId`=11591 AND `OptionIndex`=3);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42000, `VerifiedBuild`=27291 WHERE (`MenuId`=11591 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41999, `VerifiedBuild`=27291 WHERE (`MenuId`=11591 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41998, `VerifiedBuild`=27291 WHERE (`MenuId`=11591 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42004, `VerifiedBuild`=27291 WHERE (`MenuId`=11590 AND `OptionIndex`=3);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42000, `VerifiedBuild`=27291 WHERE (`MenuId`=11590 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41999, `VerifiedBuild`=27291 WHERE (`MenuId`=11590 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41998, `VerifiedBuild`=27291 WHERE (`MenuId`=11590 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42004, `VerifiedBuild`=27291 WHERE (`MenuId`=11589 AND `OptionIndex`=3);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42000, `VerifiedBuild`=27291 WHERE (`MenuId`=11589 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41999, `VerifiedBuild`=27291 WHERE (`MenuId`=11589 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41998, `VerifiedBuild`=27291 WHERE (`MenuId`=11589 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42004, `VerifiedBuild`=27291 WHERE (`MenuId`=11588 AND `OptionIndex`=3);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42000, `VerifiedBuild`=27291 WHERE (`MenuId`=11588 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41999, `VerifiedBuild`=27291 WHERE (`MenuId`=11588 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41998, `VerifiedBuild`=27291 WHERE (`MenuId`=11588 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42000, `VerifiedBuild`=27291 WHERE (`MenuId`=11593 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41999, `VerifiedBuild`=27291 WHERE (`MenuId`=11593 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41998, `VerifiedBuild`=27291 WHERE (`MenuId`=11593 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42002, `VerifiedBuild`=27291 WHERE (`MenuId`=11586 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42004, `VerifiedBuild`=27291 WHERE (`MenuId`=11592 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42004, `VerifiedBuild`=27291 WHERE (`MenuId`=11591 AND `OptionIndex`=3);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42000, `VerifiedBuild`=27291 WHERE (`MenuId`=11591 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41999, `VerifiedBuild`=27291 WHERE (`MenuId`=11591 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41998, `VerifiedBuild`=27291 WHERE (`MenuId`=11591 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42004, `VerifiedBuild`=27291 WHERE (`MenuId`=11590 AND `OptionIndex`=3);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42000, `VerifiedBuild`=27291 WHERE (`MenuId`=11590 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41999, `VerifiedBuild`=27291 WHERE (`MenuId`=11590 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41998, `VerifiedBuild`=27291 WHERE (`MenuId`=11590 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42004, `VerifiedBuild`=27291 WHERE (`MenuId`=11589 AND `OptionIndex`=3);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42000, `VerifiedBuild`=27291 WHERE (`MenuId`=11589 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41999, `VerifiedBuild`=27291 WHERE (`MenuId`=11589 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41998, `VerifiedBuild`=27291 WHERE (`MenuId`=11589 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42004, `VerifiedBuild`=27291 WHERE (`MenuId`=11588 AND `OptionIndex`=3);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42000, `VerifiedBuild`=27291 WHERE (`MenuId`=11588 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41999, `VerifiedBuild`=27291 WHERE (`MenuId`=11588 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41998, `VerifiedBuild`=27291 WHERE (`MenuId`=11588 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42000, `VerifiedBuild`=27291 WHERE (`MenuId`=11593 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41999, `VerifiedBuild`=27291 WHERE (`MenuId`=11593 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41998, `VerifiedBuild`=27291 WHERE (`MenuId`=11593 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42002, `VerifiedBuild`=27291 WHERE (`MenuId`=11586 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42004, `VerifiedBuild`=27291 WHERE (`MenuId`=11592 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42004, `VerifiedBuild`=27291 WHERE (`MenuId`=11591 AND `OptionIndex`=3);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42000, `VerifiedBuild`=27291 WHERE (`MenuId`=11591 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41999, `VerifiedBuild`=27291 WHERE (`MenuId`=11591 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41998, `VerifiedBuild`=27291 WHERE (`MenuId`=11591 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42004, `VerifiedBuild`=27291 WHERE (`MenuId`=11590 AND `OptionIndex`=3);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42000, `VerifiedBuild`=27291 WHERE (`MenuId`=11590 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41999, `VerifiedBuild`=27291 WHERE (`MenuId`=11590 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41998, `VerifiedBuild`=27291 WHERE (`MenuId`=11590 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42004, `VerifiedBuild`=27291 WHERE (`MenuId`=11589 AND `OptionIndex`=3);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42000, `VerifiedBuild`=27291 WHERE (`MenuId`=11589 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41999, `VerifiedBuild`=27291 WHERE (`MenuId`=11589 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41998, `VerifiedBuild`=27291 WHERE (`MenuId`=11589 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42004, `VerifiedBuild`=27291 WHERE (`MenuId`=11588 AND `OptionIndex`=3);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42000, `VerifiedBuild`=27291 WHERE (`MenuId`=11588 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41999, `VerifiedBuild`=27291 WHERE (`MenuId`=11588 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41998, `VerifiedBuild`=27291 WHERE (`MenuId`=11588 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42000, `VerifiedBuild`=27291 WHERE (`MenuId`=11593 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41999, `VerifiedBuild`=27291 WHERE (`MenuId`=11593 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41998, `VerifiedBuild`=27291 WHERE (`MenuId`=11593 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42002, `VerifiedBuild`=27291 WHERE (`MenuId`=11586 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42004, `VerifiedBuild`=27291 WHERE (`MenuId`=11592 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42004, `VerifiedBuild`=27291 WHERE (`MenuId`=11591 AND `OptionIndex`=3);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42000, `VerifiedBuild`=27291 WHERE (`MenuId`=11591 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41999, `VerifiedBuild`=27291 WHERE (`MenuId`=11591 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41998, `VerifiedBuild`=27291 WHERE (`MenuId`=11591 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42004, `VerifiedBuild`=27291 WHERE (`MenuId`=11590 AND `OptionIndex`=3);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42000, `VerifiedBuild`=27291 WHERE (`MenuId`=11590 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41999, `VerifiedBuild`=27291 WHERE (`MenuId`=11590 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41998, `VerifiedBuild`=27291 WHERE (`MenuId`=11590 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42004, `VerifiedBuild`=27291 WHERE (`MenuId`=11589 AND `OptionIndex`=3);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42000, `VerifiedBuild`=27291 WHERE (`MenuId`=11589 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41999, `VerifiedBuild`=27291 WHERE (`MenuId`=11589 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41998, `VerifiedBuild`=27291 WHERE (`MenuId`=11589 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42004, `VerifiedBuild`=27291 WHERE (`MenuId`=11588 AND `OptionIndex`=3);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42000, `VerifiedBuild`=27291 WHERE (`MenuId`=11588 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41999, `VerifiedBuild`=27291 WHERE (`MenuId`=11588 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41998, `VerifiedBuild`=27291 WHERE (`MenuId`=11588 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42000, `VerifiedBuild`=27291 WHERE (`MenuId`=11593 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41999, `VerifiedBuild`=27291 WHERE (`MenuId`=11593 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41998, `VerifiedBuild`=27291 WHERE (`MenuId`=11593 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42002, `VerifiedBuild`=27291 WHERE (`MenuId`=11586 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42002, `VerifiedBuild`=27291 WHERE (`MenuId`=11586 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42002, `VerifiedBuild`=27291 WHERE (`MenuId`=11586 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42004, `VerifiedBuild`=27291 WHERE (`MenuId`=11592 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42004, `VerifiedBuild`=27291 WHERE (`MenuId`=11591 AND `OptionIndex`=3);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42000, `VerifiedBuild`=27291 WHERE (`MenuId`=11591 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41999, `VerifiedBuild`=27291 WHERE (`MenuId`=11591 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41998, `VerifiedBuild`=27291 WHERE (`MenuId`=11591 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42004, `VerifiedBuild`=27291 WHERE (`MenuId`=11590 AND `OptionIndex`=3);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42000, `VerifiedBuild`=27291 WHERE (`MenuId`=11590 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41999, `VerifiedBuild`=27291 WHERE (`MenuId`=11590 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41998, `VerifiedBuild`=27291 WHERE (`MenuId`=11590 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42004, `VerifiedBuild`=27291 WHERE (`MenuId`=11589 AND `OptionIndex`=3);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42000, `VerifiedBuild`=27291 WHERE (`MenuId`=11589 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41999, `VerifiedBuild`=27291 WHERE (`MenuId`=11589 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41998, `VerifiedBuild`=27291 WHERE (`MenuId`=11589 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42004, `VerifiedBuild`=27291 WHERE (`MenuId`=11588 AND `OptionIndex`=3);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42000, `VerifiedBuild`=27291 WHERE (`MenuId`=11588 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41999, `VerifiedBuild`=27291 WHERE (`MenuId`=11588 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41998, `VerifiedBuild`=27291 WHERE (`MenuId`=11588 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42000, `VerifiedBuild`=27291 WHERE (`MenuId`=11593 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41999, `VerifiedBuild`=27291 WHERE (`MenuId`=11593 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41998, `VerifiedBuild`=27291 WHERE (`MenuId`=11593 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42002, `VerifiedBuild`=27291 WHERE (`MenuId`=11586 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42000, `VerifiedBuild`=27291 WHERE (`MenuId`=11593 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41999, `VerifiedBuild`=27291 WHERE (`MenuId`=11593 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41998, `VerifiedBuild`=27291 WHERE (`MenuId`=11593 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42002, `VerifiedBuild`=27291 WHERE (`MenuId`=11586 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42004, `VerifiedBuild`=27291 WHERE (`MenuId`=11592 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42004, `VerifiedBuild`=27291 WHERE (`MenuId`=11591 AND `OptionIndex`=3);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42000, `VerifiedBuild`=27291 WHERE (`MenuId`=11591 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41999, `VerifiedBuild`=27291 WHERE (`MenuId`=11591 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41998, `VerifiedBuild`=27291 WHERE (`MenuId`=11591 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42004, `VerifiedBuild`=27291 WHERE (`MenuId`=11590 AND `OptionIndex`=3);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42000, `VerifiedBuild`=27291 WHERE (`MenuId`=11590 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41999, `VerifiedBuild`=27291 WHERE (`MenuId`=11590 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41998, `VerifiedBuild`=27291 WHERE (`MenuId`=11590 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42004, `VerifiedBuild`=27291 WHERE (`MenuId`=11589 AND `OptionIndex`=3);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42000, `VerifiedBuild`=27291 WHERE (`MenuId`=11589 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41999, `VerifiedBuild`=27291 WHERE (`MenuId`=11589 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41998, `VerifiedBuild`=27291 WHERE (`MenuId`=11589 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42004, `VerifiedBuild`=27291 WHERE (`MenuId`=11588 AND `OptionIndex`=3);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42000, `VerifiedBuild`=27291 WHERE (`MenuId`=11588 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41999, `VerifiedBuild`=27291 WHERE (`MenuId`=11588 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41998, `VerifiedBuild`=27291 WHERE (`MenuId`=11588 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42000, `VerifiedBuild`=27291 WHERE (`MenuId`=11593 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41999, `VerifiedBuild`=27291 WHERE (`MenuId`=11593 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41998, `VerifiedBuild`=27291 WHERE (`MenuId`=11593 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42002, `VerifiedBuild`=27291 WHERE (`MenuId`=11586 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42004, `VerifiedBuild`=27291 WHERE (`MenuId`=11592 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42004, `VerifiedBuild`=27291 WHERE (`MenuId`=11591 AND `OptionIndex`=3);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42000, `VerifiedBuild`=27291 WHERE (`MenuId`=11591 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41999, `VerifiedBuild`=27291 WHERE (`MenuId`=11591 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41998, `VerifiedBuild`=27291 WHERE (`MenuId`=11591 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42004, `VerifiedBuild`=27291 WHERE (`MenuId`=11590 AND `OptionIndex`=3);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42000, `VerifiedBuild`=27291 WHERE (`MenuId`=11590 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41999, `VerifiedBuild`=27291 WHERE (`MenuId`=11590 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41998, `VerifiedBuild`=27291 WHERE (`MenuId`=11590 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42004, `VerifiedBuild`=27291 WHERE (`MenuId`=11589 AND `OptionIndex`=3);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42000, `VerifiedBuild`=27291 WHERE (`MenuId`=11589 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41999, `VerifiedBuild`=27291 WHERE (`MenuId`=11589 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41998, `VerifiedBuild`=27291 WHERE (`MenuId`=11589 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42004, `VerifiedBuild`=27291 WHERE (`MenuId`=11588 AND `OptionIndex`=3);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42000, `VerifiedBuild`=27291 WHERE (`MenuId`=11588 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41999, `VerifiedBuild`=27291 WHERE (`MenuId`=11588 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41998, `VerifiedBuild`=27291 WHERE (`MenuId`=11588 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42000, `VerifiedBuild`=27291 WHERE (`MenuId`=11593 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41999, `VerifiedBuild`=27291 WHERE (`MenuId`=11593 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41998, `VerifiedBuild`=27291 WHERE (`MenuId`=11593 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42002, `VerifiedBuild`=27291 WHERE (`MenuId`=11586 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42004, `VerifiedBuild`=27291 WHERE (`MenuId`=11592 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42004, `VerifiedBuild`=27291 WHERE (`MenuId`=11591 AND `OptionIndex`=3);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42000, `VerifiedBuild`=27291 WHERE (`MenuId`=11591 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41999, `VerifiedBuild`=27291 WHERE (`MenuId`=11591 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41998, `VerifiedBuild`=27291 WHERE (`MenuId`=11591 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42004, `VerifiedBuild`=27291 WHERE (`MenuId`=11590 AND `OptionIndex`=3);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42000, `VerifiedBuild`=27291 WHERE (`MenuId`=11590 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41999, `VerifiedBuild`=27291 WHERE (`MenuId`=11590 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41998, `VerifiedBuild`=27291 WHERE (`MenuId`=11590 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42004, `VerifiedBuild`=27291 WHERE (`MenuId`=11589 AND `OptionIndex`=3);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42000, `VerifiedBuild`=27291 WHERE (`MenuId`=11589 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41999, `VerifiedBuild`=27291 WHERE (`MenuId`=11589 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41998, `VerifiedBuild`=27291 WHERE (`MenuId`=11589 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42004, `VerifiedBuild`=27291 WHERE (`MenuId`=11588 AND `OptionIndex`=3);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42000, `VerifiedBuild`=27291 WHERE (`MenuId`=11588 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41999, `VerifiedBuild`=27291 WHERE (`MenuId`=11588 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41998, `VerifiedBuild`=27291 WHERE (`MenuId`=11588 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42000, `VerifiedBuild`=27291 WHERE (`MenuId`=11593 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41999, `VerifiedBuild`=27291 WHERE (`MenuId`=11593 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41998, `VerifiedBuild`=27291 WHERE (`MenuId`=11593 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42002, `VerifiedBuild`=27291 WHERE (`MenuId`=11586 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42004, `VerifiedBuild`=27291 WHERE (`MenuId`=11592 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42004, `VerifiedBuild`=27291 WHERE (`MenuId`=11591 AND `OptionIndex`=3);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42000, `VerifiedBuild`=27291 WHERE (`MenuId`=11591 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41999, `VerifiedBuild`=27291 WHERE (`MenuId`=11591 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41998, `VerifiedBuild`=27291 WHERE (`MenuId`=11591 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42004, `VerifiedBuild`=27291 WHERE (`MenuId`=11590 AND `OptionIndex`=3);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42000, `VerifiedBuild`=27291 WHERE (`MenuId`=11590 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41999, `VerifiedBuild`=27291 WHERE (`MenuId`=11590 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41998, `VerifiedBuild`=27291 WHERE (`MenuId`=11590 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42004, `VerifiedBuild`=27291 WHERE (`MenuId`=11589 AND `OptionIndex`=3);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42000, `VerifiedBuild`=27291 WHERE (`MenuId`=11589 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41999, `VerifiedBuild`=27291 WHERE (`MenuId`=11589 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41998, `VerifiedBuild`=27291 WHERE (`MenuId`=11589 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42004, `VerifiedBuild`=27291 WHERE (`MenuId`=11588 AND `OptionIndex`=3);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42000, `VerifiedBuild`=27291 WHERE (`MenuId`=11588 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41999, `VerifiedBuild`=27291 WHERE (`MenuId`=11588 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41998, `VerifiedBuild`=27291 WHERE (`MenuId`=11588 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42000, `VerifiedBuild`=27291 WHERE (`MenuId`=11593 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41999, `VerifiedBuild`=27291 WHERE (`MenuId`=11593 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41998, `VerifiedBuild`=27291 WHERE (`MenuId`=11593 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42002, `VerifiedBuild`=27291 WHERE (`MenuId`=11586 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42004, `VerifiedBuild`=27291 WHERE (`MenuId`=11592 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42004, `VerifiedBuild`=27291 WHERE (`MenuId`=11591 AND `OptionIndex`=3);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42000, `VerifiedBuild`=27291 WHERE (`MenuId`=11591 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41999, `VerifiedBuild`=27291 WHERE (`MenuId`=11591 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41998, `VerifiedBuild`=27291 WHERE (`MenuId`=11591 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42004, `VerifiedBuild`=27291 WHERE (`MenuId`=11590 AND `OptionIndex`=3);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42000, `VerifiedBuild`=27291 WHERE (`MenuId`=11590 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41999, `VerifiedBuild`=27291 WHERE (`MenuId`=11590 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41998, `VerifiedBuild`=27291 WHERE (`MenuId`=11590 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42004, `VerifiedBuild`=27291 WHERE (`MenuId`=11589 AND `OptionIndex`=3);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42000, `VerifiedBuild`=27291 WHERE (`MenuId`=11589 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41999, `VerifiedBuild`=27291 WHERE (`MenuId`=11589 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41998, `VerifiedBuild`=27291 WHERE (`MenuId`=11589 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42004, `VerifiedBuild`=27291 WHERE (`MenuId`=11588 AND `OptionIndex`=3);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42000, `VerifiedBuild`=27291 WHERE (`MenuId`=11588 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41999, `VerifiedBuild`=27291 WHERE (`MenuId`=11588 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41998, `VerifiedBuild`=27291 WHERE (`MenuId`=11588 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42000, `VerifiedBuild`=27291 WHERE (`MenuId`=11593 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41999, `VerifiedBuild`=27291 WHERE (`MenuId`=11593 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41998, `VerifiedBuild`=27291 WHERE (`MenuId`=11593 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42002, `VerifiedBuild`=27291 WHERE (`MenuId`=11586 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42004, `VerifiedBuild`=27291 WHERE (`MenuId`=11592 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42004, `VerifiedBuild`=27291 WHERE (`MenuId`=11591 AND `OptionIndex`=3);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42000, `VerifiedBuild`=27291 WHERE (`MenuId`=11591 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41999, `VerifiedBuild`=27291 WHERE (`MenuId`=11591 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41998, `VerifiedBuild`=27291 WHERE (`MenuId`=11591 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42004, `VerifiedBuild`=27291 WHERE (`MenuId`=11590 AND `OptionIndex`=3);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42000, `VerifiedBuild`=27291 WHERE (`MenuId`=11590 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41999, `VerifiedBuild`=27291 WHERE (`MenuId`=11590 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41998, `VerifiedBuild`=27291 WHERE (`MenuId`=11590 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42004, `VerifiedBuild`=27291 WHERE (`MenuId`=11589 AND `OptionIndex`=3);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42000, `VerifiedBuild`=27291 WHERE (`MenuId`=11589 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41999, `VerifiedBuild`=27291 WHERE (`MenuId`=11589 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41998, `VerifiedBuild`=27291 WHERE (`MenuId`=11589 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42004, `VerifiedBuild`=27291 WHERE (`MenuId`=11588 AND `OptionIndex`=3);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42000, `VerifiedBuild`=27291 WHERE (`MenuId`=11588 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41999, `VerifiedBuild`=27291 WHERE (`MenuId`=11588 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41998, `VerifiedBuild`=27291 WHERE (`MenuId`=11588 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42000, `VerifiedBuild`=27291 WHERE (`MenuId`=11593 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41999, `VerifiedBuild`=27291 WHERE (`MenuId`=11593 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41998, `VerifiedBuild`=27291 WHERE (`MenuId`=11593 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42002, `VerifiedBuild`=27291 WHERE (`MenuId`=11586 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42004, `VerifiedBuild`=27291 WHERE (`MenuId`=11592 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42004, `VerifiedBuild`=27291 WHERE (`MenuId`=11591 AND `OptionIndex`=3);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42000, `VerifiedBuild`=27291 WHERE (`MenuId`=11591 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41999, `VerifiedBuild`=27291 WHERE (`MenuId`=11591 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41998, `VerifiedBuild`=27291 WHERE (`MenuId`=11591 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42004, `VerifiedBuild`=27291 WHERE (`MenuId`=11590 AND `OptionIndex`=3);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42000, `VerifiedBuild`=27291 WHERE (`MenuId`=11590 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41999, `VerifiedBuild`=27291 WHERE (`MenuId`=11590 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41998, `VerifiedBuild`=27291 WHERE (`MenuId`=11590 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42004, `VerifiedBuild`=27291 WHERE (`MenuId`=11589 AND `OptionIndex`=3);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42000, `VerifiedBuild`=27291 WHERE (`MenuId`=11589 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41999, `VerifiedBuild`=27291 WHERE (`MenuId`=11589 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41998, `VerifiedBuild`=27291 WHERE (`MenuId`=11589 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42004, `VerifiedBuild`=27291 WHERE (`MenuId`=11588 AND `OptionIndex`=3);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42000, `VerifiedBuild`=27291 WHERE (`MenuId`=11588 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41999, `VerifiedBuild`=27291 WHERE (`MenuId`=11588 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41998, `VerifiedBuild`=27291 WHERE (`MenuId`=11588 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42000, `VerifiedBuild`=27291 WHERE (`MenuId`=11593 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41999, `VerifiedBuild`=27291 WHERE (`MenuId`=11593 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41998, `VerifiedBuild`=27291 WHERE (`MenuId`=11593 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42002, `VerifiedBuild`=27291 WHERE (`MenuId`=11586 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42004, `VerifiedBuild`=27291 WHERE (`MenuId`=11592 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42004, `VerifiedBuild`=27291 WHERE (`MenuId`=11591 AND `OptionIndex`=3);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42000, `VerifiedBuild`=27291 WHERE (`MenuId`=11591 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41999, `VerifiedBuild`=27291 WHERE (`MenuId`=11591 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41998, `VerifiedBuild`=27291 WHERE (`MenuId`=11591 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42004, `VerifiedBuild`=27291 WHERE (`MenuId`=11590 AND `OptionIndex`=3);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42000, `VerifiedBuild`=27291 WHERE (`MenuId`=11590 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41999, `VerifiedBuild`=27291 WHERE (`MenuId`=11590 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41998, `VerifiedBuild`=27291 WHERE (`MenuId`=11590 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42004, `VerifiedBuild`=27291 WHERE (`MenuId`=11589 AND `OptionIndex`=3);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42000, `VerifiedBuild`=27291 WHERE (`MenuId`=11589 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41999, `VerifiedBuild`=27291 WHERE (`MenuId`=11589 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41998, `VerifiedBuild`=27291 WHERE (`MenuId`=11589 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42004, `VerifiedBuild`=27291 WHERE (`MenuId`=11588 AND `OptionIndex`=3);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42000, `VerifiedBuild`=27291 WHERE (`MenuId`=11588 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41999, `VerifiedBuild`=27291 WHERE (`MenuId`=11588 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41998, `VerifiedBuild`=27291 WHERE (`MenuId`=11588 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42000, `VerifiedBuild`=27291 WHERE (`MenuId`=11593 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41999, `VerifiedBuild`=27291 WHERE (`MenuId`=11593 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41998, `VerifiedBuild`=27291 WHERE (`MenuId`=11593 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42002, `VerifiedBuild`=27291 WHERE (`MenuId`=11586 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42004, `VerifiedBuild`=27291 WHERE (`MenuId`=11592 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42004, `VerifiedBuild`=27291 WHERE (`MenuId`=11591 AND `OptionIndex`=3);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42000, `VerifiedBuild`=27291 WHERE (`MenuId`=11591 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41999, `VerifiedBuild`=27291 WHERE (`MenuId`=11591 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41998, `VerifiedBuild`=27291 WHERE (`MenuId`=11591 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42004, `VerifiedBuild`=27291 WHERE (`MenuId`=11590 AND `OptionIndex`=3);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42000, `VerifiedBuild`=27291 WHERE (`MenuId`=11590 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41999, `VerifiedBuild`=27291 WHERE (`MenuId`=11590 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41998, `VerifiedBuild`=27291 WHERE (`MenuId`=11590 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42004, `VerifiedBuild`=27291 WHERE (`MenuId`=11589 AND `OptionIndex`=3);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42000, `VerifiedBuild`=27291 WHERE (`MenuId`=11589 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41999, `VerifiedBuild`=27291 WHERE (`MenuId`=11589 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41998, `VerifiedBuild`=27291 WHERE (`MenuId`=11589 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42004, `VerifiedBuild`=27291 WHERE (`MenuId`=11588 AND `OptionIndex`=3);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42000, `VerifiedBuild`=27291 WHERE (`MenuId`=11588 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41999, `VerifiedBuild`=27291 WHERE (`MenuId`=11588 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41998, `VerifiedBuild`=27291 WHERE (`MenuId`=11588 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42000, `VerifiedBuild`=27291 WHERE (`MenuId`=11593 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41999, `VerifiedBuild`=27291 WHERE (`MenuId`=11593 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41998, `VerifiedBuild`=27291 WHERE (`MenuId`=11593 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42002, `VerifiedBuild`=27291 WHERE (`MenuId`=11586 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42004, `VerifiedBuild`=27291 WHERE (`MenuId`=11592 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42004, `VerifiedBuild`=27291 WHERE (`MenuId`=11591 AND `OptionIndex`=3);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42000, `VerifiedBuild`=27291 WHERE (`MenuId`=11591 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41999, `VerifiedBuild`=27291 WHERE (`MenuId`=11591 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41998, `VerifiedBuild`=27291 WHERE (`MenuId`=11591 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42004, `VerifiedBuild`=27291 WHERE (`MenuId`=11590 AND `OptionIndex`=3);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42000, `VerifiedBuild`=27291 WHERE (`MenuId`=11590 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41999, `VerifiedBuild`=27291 WHERE (`MenuId`=11590 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41998, `VerifiedBuild`=27291 WHERE (`MenuId`=11590 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42004, `VerifiedBuild`=27291 WHERE (`MenuId`=11589 AND `OptionIndex`=3);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42000, `VerifiedBuild`=27291 WHERE (`MenuId`=11589 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41999, `VerifiedBuild`=27291 WHERE (`MenuId`=11589 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41998, `VerifiedBuild`=27291 WHERE (`MenuId`=11589 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42004, `VerifiedBuild`=27291 WHERE (`MenuId`=11588 AND `OptionIndex`=3);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42000, `VerifiedBuild`=27291 WHERE (`MenuId`=11588 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41999, `VerifiedBuild`=27291 WHERE (`MenuId`=11588 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41998, `VerifiedBuild`=27291 WHERE (`MenuId`=11588 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42000, `VerifiedBuild`=27291 WHERE (`MenuId`=11593 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41999, `VerifiedBuild`=27291 WHERE (`MenuId`=11593 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41998, `VerifiedBuild`=27291 WHERE (`MenuId`=11593 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42002, `VerifiedBuild`=27291 WHERE (`MenuId`=11586 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42004, `VerifiedBuild`=27291 WHERE (`MenuId`=11592 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42004, `VerifiedBuild`=27291 WHERE (`MenuId`=11591 AND `OptionIndex`=3);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42000, `VerifiedBuild`=27291 WHERE (`MenuId`=11591 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41999, `VerifiedBuild`=27291 WHERE (`MenuId`=11591 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41998, `VerifiedBuild`=27291 WHERE (`MenuId`=11591 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42004, `VerifiedBuild`=27291 WHERE (`MenuId`=11590 AND `OptionIndex`=3);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42000, `VerifiedBuild`=27291 WHERE (`MenuId`=11590 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41999, `VerifiedBuild`=27291 WHERE (`MenuId`=11590 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41998, `VerifiedBuild`=27291 WHERE (`MenuId`=11590 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42004, `VerifiedBuild`=27291 WHERE (`MenuId`=11589 AND `OptionIndex`=3);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42000, `VerifiedBuild`=27291 WHERE (`MenuId`=11589 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41999, `VerifiedBuild`=27291 WHERE (`MenuId`=11589 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41998, `VerifiedBuild`=27291 WHERE (`MenuId`=11589 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42004, `VerifiedBuild`=27291 WHERE (`MenuId`=11588 AND `OptionIndex`=3);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42000, `VerifiedBuild`=27291 WHERE (`MenuId`=11588 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41999, `VerifiedBuild`=27291 WHERE (`MenuId`=11588 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41998, `VerifiedBuild`=27291 WHERE (`MenuId`=11588 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42000, `VerifiedBuild`=27291 WHERE (`MenuId`=11593 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41999, `VerifiedBuild`=27291 WHERE (`MenuId`=11593 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41998, `VerifiedBuild`=27291 WHERE (`MenuId`=11593 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42002, `VerifiedBuild`=27291 WHERE (`MenuId`=11586 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42004, `VerifiedBuild`=27291 WHERE (`MenuId`=11592 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42004, `VerifiedBuild`=27291 WHERE (`MenuId`=11591 AND `OptionIndex`=3);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42000, `VerifiedBuild`=27291 WHERE (`MenuId`=11591 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41999, `VerifiedBuild`=27291 WHERE (`MenuId`=11591 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41998, `VerifiedBuild`=27291 WHERE (`MenuId`=11591 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42004, `VerifiedBuild`=27291 WHERE (`MenuId`=11590 AND `OptionIndex`=3);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42000, `VerifiedBuild`=27291 WHERE (`MenuId`=11590 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41999, `VerifiedBuild`=27291 WHERE (`MenuId`=11590 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41998, `VerifiedBuild`=27291 WHERE (`MenuId`=11590 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42004, `VerifiedBuild`=27291 WHERE (`MenuId`=11589 AND `OptionIndex`=3);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42000, `VerifiedBuild`=27291 WHERE (`MenuId`=11589 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41999, `VerifiedBuild`=27291 WHERE (`MenuId`=11589 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41998, `VerifiedBuild`=27291 WHERE (`MenuId`=11589 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42004, `VerifiedBuild`=27291 WHERE (`MenuId`=11588 AND `OptionIndex`=3);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42000, `VerifiedBuild`=27291 WHERE (`MenuId`=11588 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41999, `VerifiedBuild`=27291 WHERE (`MenuId`=11588 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41998, `VerifiedBuild`=27291 WHERE (`MenuId`=11588 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42000, `VerifiedBuild`=27291 WHERE (`MenuId`=11593 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41999, `VerifiedBuild`=27291 WHERE (`MenuId`=11593 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41998, `VerifiedBuild`=27291 WHERE (`MenuId`=11593 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42002, `VerifiedBuild`=27291 WHERE (`MenuId`=11586 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42004, `VerifiedBuild`=27291 WHERE (`MenuId`=11592 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42004, `VerifiedBuild`=27291 WHERE (`MenuId`=11591 AND `OptionIndex`=3);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42000, `VerifiedBuild`=27291 WHERE (`MenuId`=11591 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41999, `VerifiedBuild`=27291 WHERE (`MenuId`=11591 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41998, `VerifiedBuild`=27291 WHERE (`MenuId`=11591 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42004, `VerifiedBuild`=27291 WHERE (`MenuId`=11590 AND `OptionIndex`=3);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42000, `VerifiedBuild`=27291 WHERE (`MenuId`=11590 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41999, `VerifiedBuild`=27291 WHERE (`MenuId`=11590 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41998, `VerifiedBuild`=27291 WHERE (`MenuId`=11590 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42004, `VerifiedBuild`=27291 WHERE (`MenuId`=11589 AND `OptionIndex`=3);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42000, `VerifiedBuild`=27291 WHERE (`MenuId`=11589 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41999, `VerifiedBuild`=27291 WHERE (`MenuId`=11589 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41998, `VerifiedBuild`=27291 WHERE (`MenuId`=11589 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42004, `VerifiedBuild`=27291 WHERE (`MenuId`=11588 AND `OptionIndex`=3);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42000, `VerifiedBuild`=27291 WHERE (`MenuId`=11588 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41999, `VerifiedBuild`=27291 WHERE (`MenuId`=11588 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41998, `VerifiedBuild`=27291 WHERE (`MenuId`=11588 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42000, `VerifiedBuild`=27291 WHERE (`MenuId`=11593 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41999, `VerifiedBuild`=27291 WHERE (`MenuId`=11593 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41998, `VerifiedBuild`=27291 WHERE (`MenuId`=11593 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42002, `VerifiedBuild`=27291 WHERE (`MenuId`=11586 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42004, `VerifiedBuild`=27291 WHERE (`MenuId`=11592 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42004, `VerifiedBuild`=27291 WHERE (`MenuId`=11591 AND `OptionIndex`=3);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42000, `VerifiedBuild`=27291 WHERE (`MenuId`=11591 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41999, `VerifiedBuild`=27291 WHERE (`MenuId`=11591 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41998, `VerifiedBuild`=27291 WHERE (`MenuId`=11591 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42004, `VerifiedBuild`=27291 WHERE (`MenuId`=11590 AND `OptionIndex`=3);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42000, `VerifiedBuild`=27291 WHERE (`MenuId`=11590 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41999, `VerifiedBuild`=27291 WHERE (`MenuId`=11590 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41998, `VerifiedBuild`=27291 WHERE (`MenuId`=11590 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42004, `VerifiedBuild`=27291 WHERE (`MenuId`=11589 AND `OptionIndex`=3);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42000, `VerifiedBuild`=27291 WHERE (`MenuId`=11589 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41999, `VerifiedBuild`=27291 WHERE (`MenuId`=11589 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41998, `VerifiedBuild`=27291 WHERE (`MenuId`=11589 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42004, `VerifiedBuild`=27291 WHERE (`MenuId`=11588 AND `OptionIndex`=3);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42000, `VerifiedBuild`=27291 WHERE (`MenuId`=11588 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41999, `VerifiedBuild`=27291 WHERE (`MenuId`=11588 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41998, `VerifiedBuild`=27291 WHERE (`MenuId`=11588 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42000, `VerifiedBuild`=27291 WHERE (`MenuId`=11593 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41999, `VerifiedBuild`=27291 WHERE (`MenuId`=11593 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41998, `VerifiedBuild`=27291 WHERE (`MenuId`=11593 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42002, `VerifiedBuild`=27291 WHERE (`MenuId`=11586 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42004, `VerifiedBuild`=27291 WHERE (`MenuId`=11592 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42004, `VerifiedBuild`=27291 WHERE (`MenuId`=11591 AND `OptionIndex`=3);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42000, `VerifiedBuild`=27291 WHERE (`MenuId`=11591 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41999, `VerifiedBuild`=27291 WHERE (`MenuId`=11591 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41998, `VerifiedBuild`=27291 WHERE (`MenuId`=11591 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42004, `VerifiedBuild`=27291 WHERE (`MenuId`=11590 AND `OptionIndex`=3);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42000, `VerifiedBuild`=27291 WHERE (`MenuId`=11590 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41999, `VerifiedBuild`=27291 WHERE (`MenuId`=11590 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41998, `VerifiedBuild`=27291 WHERE (`MenuId`=11590 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42004, `VerifiedBuild`=27291 WHERE (`MenuId`=11589 AND `OptionIndex`=3);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42000, `VerifiedBuild`=27291 WHERE (`MenuId`=11589 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41999, `VerifiedBuild`=27291 WHERE (`MenuId`=11589 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41998, `VerifiedBuild`=27291 WHERE (`MenuId`=11589 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42004, `VerifiedBuild`=27291 WHERE (`MenuId`=11588 AND `OptionIndex`=3);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42000, `VerifiedBuild`=27291 WHERE (`MenuId`=11588 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41999, `VerifiedBuild`=27291 WHERE (`MenuId`=11588 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41998, `VerifiedBuild`=27291 WHERE (`MenuId`=11588 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42000, `VerifiedBuild`=27291 WHERE (`MenuId`=11593 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41999, `VerifiedBuild`=27291 WHERE (`MenuId`=11593 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41998, `VerifiedBuild`=27291 WHERE (`MenuId`=11593 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42002, `VerifiedBuild`=27291 WHERE (`MenuId`=11586 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42004, `VerifiedBuild`=27291 WHERE (`MenuId`=11592 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42004, `VerifiedBuild`=27291 WHERE (`MenuId`=11591 AND `OptionIndex`=3);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42000, `VerifiedBuild`=27291 WHERE (`MenuId`=11591 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41999, `VerifiedBuild`=27291 WHERE (`MenuId`=11591 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41998, `VerifiedBuild`=27291 WHERE (`MenuId`=11591 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42004, `VerifiedBuild`=27291 WHERE (`MenuId`=11590 AND `OptionIndex`=3);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42000, `VerifiedBuild`=27291 WHERE (`MenuId`=11590 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41999, `VerifiedBuild`=27291 WHERE (`MenuId`=11590 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41998, `VerifiedBuild`=27291 WHERE (`MenuId`=11590 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42004, `VerifiedBuild`=27291 WHERE (`MenuId`=11589 AND `OptionIndex`=3);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42000, `VerifiedBuild`=27291 WHERE (`MenuId`=11589 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41999, `VerifiedBuild`=27291 WHERE (`MenuId`=11589 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41998, `VerifiedBuild`=27291 WHERE (`MenuId`=11589 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42004, `VerifiedBuild`=27291 WHERE (`MenuId`=11588 AND `OptionIndex`=3);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42000, `VerifiedBuild`=27291 WHERE (`MenuId`=11588 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41999, `VerifiedBuild`=27291 WHERE (`MenuId`=11588 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41998, `VerifiedBuild`=27291 WHERE (`MenuId`=11588 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42000, `VerifiedBuild`=27291 WHERE (`MenuId`=11593 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41999, `VerifiedBuild`=27291 WHERE (`MenuId`=11593 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41998, `VerifiedBuild`=27291 WHERE (`MenuId`=11593 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42002, `VerifiedBuild`=27291 WHERE (`MenuId`=11586 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42004, `VerifiedBuild`=27291 WHERE (`MenuId`=11592 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42004, `VerifiedBuild`=27291 WHERE (`MenuId`=11591 AND `OptionIndex`=3);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42000, `VerifiedBuild`=27291 WHERE (`MenuId`=11591 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41999, `VerifiedBuild`=27291 WHERE (`MenuId`=11591 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41998, `VerifiedBuild`=27291 WHERE (`MenuId`=11591 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42004, `VerifiedBuild`=27291 WHERE (`MenuId`=11590 AND `OptionIndex`=3);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42000, `VerifiedBuild`=27291 WHERE (`MenuId`=11590 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41999, `VerifiedBuild`=27291 WHERE (`MenuId`=11590 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41998, `VerifiedBuild`=27291 WHERE (`MenuId`=11590 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42004, `VerifiedBuild`=27291 WHERE (`MenuId`=11589 AND `OptionIndex`=3);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42000, `VerifiedBuild`=27291 WHERE (`MenuId`=11589 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41999, `VerifiedBuild`=27291 WHERE (`MenuId`=11589 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41998, `VerifiedBuild`=27291 WHERE (`MenuId`=11589 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42004, `VerifiedBuild`=27291 WHERE (`MenuId`=11588 AND `OptionIndex`=3);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42000, `VerifiedBuild`=27291 WHERE (`MenuId`=11588 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41999, `VerifiedBuild`=27291 WHERE (`MenuId`=11588 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41998, `VerifiedBuild`=27291 WHERE (`MenuId`=11588 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42000, `VerifiedBuild`=27291 WHERE (`MenuId`=11593 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41999, `VerifiedBuild`=27291 WHERE (`MenuId`=11593 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41998, `VerifiedBuild`=27291 WHERE (`MenuId`=11593 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42002, `VerifiedBuild`=27291 WHERE (`MenuId`=11586 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42004, `VerifiedBuild`=27291 WHERE (`MenuId`=11592 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42004, `VerifiedBuild`=27291 WHERE (`MenuId`=11591 AND `OptionIndex`=3);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42000, `VerifiedBuild`=27291 WHERE (`MenuId`=11591 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41999, `VerifiedBuild`=27291 WHERE (`MenuId`=11591 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41998, `VerifiedBuild`=27291 WHERE (`MenuId`=11591 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42004, `VerifiedBuild`=27291 WHERE (`MenuId`=11590 AND `OptionIndex`=3);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42000, `VerifiedBuild`=27291 WHERE (`MenuId`=11590 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41999, `VerifiedBuild`=27291 WHERE (`MenuId`=11590 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41998, `VerifiedBuild`=27291 WHERE (`MenuId`=11590 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42004, `VerifiedBuild`=27291 WHERE (`MenuId`=11589 AND `OptionIndex`=3);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42000, `VerifiedBuild`=27291 WHERE (`MenuId`=11589 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41999, `VerifiedBuild`=27291 WHERE (`MenuId`=11589 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41998, `VerifiedBuild`=27291 WHERE (`MenuId`=11589 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42004, `VerifiedBuild`=27291 WHERE (`MenuId`=11588 AND `OptionIndex`=3);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42000, `VerifiedBuild`=27291 WHERE (`MenuId`=11588 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41999, `VerifiedBuild`=27291 WHERE (`MenuId`=11588 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41998, `VerifiedBuild`=27291 WHERE (`MenuId`=11588 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42000, `VerifiedBuild`=27291 WHERE (`MenuId`=11593 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41999, `VerifiedBuild`=27291 WHERE (`MenuId`=11593 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41998, `VerifiedBuild`=27291 WHERE (`MenuId`=11593 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=42002, `VerifiedBuild`=27291 WHERE (`MenuId`=11586 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41798, `VerifiedBuild`=27291 WHERE (`MenuId`=11572 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41788, `VerifiedBuild`=27291 WHERE (`MenuId`=11571 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41788, `VerifiedBuild`=27291 WHERE (`MenuId`=11571 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41788, `VerifiedBuild`=27291 WHERE (`MenuId`=11571 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41788, `VerifiedBuild`=27291 WHERE (`MenuId`=11571 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41788, `VerifiedBuild`=27291 WHERE (`MenuId`=11571 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41788, `VerifiedBuild`=27291 WHERE (`MenuId`=11571 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41460, `VerifiedBuild`=27291 WHERE (`MenuId`=11515 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41460, `VerifiedBuild`=27291 WHERE (`MenuId`=11516 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41460, `VerifiedBuild`=27291 WHERE (`MenuId`=11517 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41223, `VerifiedBuild`=27291 WHERE (`MenuId`=11481 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41223, `VerifiedBuild`=27291 WHERE (`MenuId`=11481 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41223, `VerifiedBuild`=27291 WHERE (`MenuId`=11481 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41223, `VerifiedBuild`=27291 WHERE (`MenuId`=11481 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41223, `VerifiedBuild`=27291 WHERE (`MenuId`=11481 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41223, `VerifiedBuild`=27291 WHERE (`MenuId`=11481 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=40242, `VerifiedBuild`=27291 WHERE (`MenuId`=11352 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=40242, `VerifiedBuild`=27291 WHERE (`MenuId`=11352 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=40242, `VerifiedBuild`=27291 WHERE (`MenuId`=11352 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=40242, `VerifiedBuild`=27291 WHERE (`MenuId`=11352 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=40242, `VerifiedBuild`=27291 WHERE (`MenuId`=11352 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=40242, `VerifiedBuild`=27291 WHERE (`MenuId`=11352 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=40242, `VerifiedBuild`=27291 WHERE (`MenuId`=11352 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=40242, `VerifiedBuild`=27291 WHERE (`MenuId`=11352 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=40242, `VerifiedBuild`=27291 WHERE (`MenuId`=11352 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=40242, `VerifiedBuild`=27291 WHERE (`MenuId`=11352 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=40242, `VerifiedBuild`=27291 WHERE (`MenuId`=11352 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=40242, `VerifiedBuild`=27291 WHERE (`MenuId`=11352 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=40242, `VerifiedBuild`=27291 WHERE (`MenuId`=11352 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=40242, `VerifiedBuild`=27291 WHERE (`MenuId`=11352 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=40242, `VerifiedBuild`=27291 WHERE (`MenuId`=11352 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=40242, `VerifiedBuild`=27291 WHERE (`MenuId`=11352 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=40242, `VerifiedBuild`=27291 WHERE (`MenuId`=11352 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=40242, `VerifiedBuild`=27291 WHERE (`MenuId`=11352 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=40243, `VerifiedBuild`=27291 WHERE (`MenuId`=11351 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=40242, `VerifiedBuild`=27291 WHERE (`MenuId`=11352 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=2822, `VerifiedBuild`=27291 WHERE (`MenuId`=11538 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=2822, `VerifiedBuild`=27291 WHERE (`MenuId`=11538 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=2822, `VerifiedBuild`=27291 WHERE (`MenuId`=11538 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=2822, `VerifiedBuild`=27291 WHERE (`MenuId`=11538 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=48170, `VerifiedBuild`=27291 WHERE (`MenuId`=12370 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=8097, `VerifiedBuild`=27291 WHERE (`MenuId`=7809 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=2822, `VerifiedBuild`=27602 WHERE (`MenuId`=7481 AND `OptionIndex`=0);
DELETE FROM `gossip_menu_option_action` WHERE (`MenuId`=18335 AND `OptionIndex`=1) OR (`MenuId`=18335 AND `OptionIndex`=0) OR (`MenuId`=18333 AND `OptionIndex`=0) OR (`MenuId`=18331 AND `OptionIndex`=2) OR (`MenuId`=18331 AND `OptionIndex`=1) OR (`MenuId`=18331 AND `OptionIndex`=0) OR (`MenuId`=18412 AND `OptionIndex`=1) OR (`MenuId`=18228 AND `OptionIndex`=0) OR (`MenuId`=16353 AND `OptionIndex`=0) OR (`MenuId`=16597 AND `OptionIndex`=0) OR (`MenuId`=18275 AND `OptionIndex`=0) OR (`MenuId`=17334 AND `OptionIndex`=11) OR (`MenuId`=17372 AND `OptionIndex`=4) OR (`MenuId`=17334 AND `OptionIndex`=10) OR (`MenuId`=17372 AND `OptionIndex`=2) OR (`MenuId`=17372 AND `OptionIndex`=3) OR (`MenuId`=17372 AND `OptionIndex`=1) OR (`MenuId`=17372 AND `OptionIndex`=0) OR (`MenuId`=17334 AND `OptionIndex`=9) OR (`MenuId`=17334 AND `OptionIndex`=8) OR (`MenuId`=17349 AND `OptionIndex`=12) OR (`MenuId`=17334 AND `OptionIndex`=7) OR (`MenuId`=17349 AND `OptionIndex`=14) OR (`MenuId`=17349 AND `OptionIndex`=13) OR (`MenuId`=17349 AND `OptionIndex`=11) OR (`MenuId`=17349 AND `OptionIndex`=10) OR (`MenuId`=17349 AND `OptionIndex`=9) OR (`MenuId`=17349 AND `OptionIndex`=8) OR (`MenuId`=17349 AND `OptionIndex`=7) OR (`MenuId`=17349 AND `OptionIndex`=6) OR (`MenuId`=17349 AND `OptionIndex`=5) OR (`MenuId`=17349 AND `OptionIndex`=4) OR (`MenuId`=17349 AND `OptionIndex`=3) OR (`MenuId`=17349 AND `OptionIndex`=2) OR (`MenuId`=17349 AND `OptionIndex`=1) OR (`MenuId`=17349 AND `OptionIndex`=0) OR (`MenuId`=17334 AND `OptionIndex`=6) OR (`MenuId`=17348 AND `OptionIndex`=2) OR (`MenuId`=17334 AND `OptionIndex`=5) OR (`MenuId`=17348 AND `OptionIndex`=1) OR (`MenuId`=17348 AND `OptionIndex`=0) OR (`MenuId`=17344 AND `OptionIndex`=2) OR (`MenuId`=17334 AND `OptionIndex`=4) OR (`MenuId`=17344 AND `OptionIndex`=1) OR (`MenuId`=17344 AND `OptionIndex`=0) OR (`MenuId`=17334 AND `OptionIndex`=3) OR (`MenuId`=17334 AND `OptionIndex`=2) OR (`MenuId`=17334 AND `OptionIndex`=1) OR (`MenuId`=17334 AND `OptionIndex`=0) OR (`MenuId`=16236 AND `OptionIndex`=0) OR (`MenuId`=16872 AND `OptionIndex`=4) OR (`MenuId`=16526 AND `OptionIndex`=1) OR (`MenuId`=16526 AND `OptionIndex`=0) OR (`MenuId`=17000 AND `OptionIndex`=4) OR (`MenuId`=17005 AND `OptionIndex`=0) OR (`MenuId`=17000 AND `OptionIndex`=3) OR (`MenuId`=16613 AND `OptionIndex`=0) OR (`MenuId`=13892 AND `OptionIndex`=0) OR (`MenuId`=13893 AND `OptionIndex`=0) OR (`MenuId`=13462 AND `OptionIndex`=3) OR (`MenuId`=13462 AND `OptionIndex`=1) OR (`MenuId`=13464 AND `OptionIndex`=2) OR (`MenuId`=13301 AND `OptionIndex`=4) OR (`MenuId`=13748 AND `OptionIndex`=0) OR (`MenuId`=13747 AND `OptionIndex`=0) OR (`MenuId`=13746 AND `OptionIndex`=0) OR (`MenuId`=13745 AND `OptionIndex`=0) OR (`MenuId`=12115 AND `OptionIndex`=0) OR (`MenuId`=12114 AND `OptionIndex`=0) OR (`MenuId`=12113 AND `OptionIndex`=0) OR (`MenuId`=12136 AND `OptionIndex`=0) OR (`MenuId`=12137 AND `OptionIndex`=0) OR (`MenuId`=12138 AND `OptionIndex`=0) OR (`MenuId`=11514 AND `OptionIndex`=0) OR (`MenuId`=11510 AND `OptionIndex`=0) OR (`MenuId`=11511 AND `OptionIndex`=0) OR (`MenuId`=11508 AND `OptionIndex`=0) OR (`MenuId`=11509 AND `OptionIndex`=0) OR (`MenuId`=11489 AND `OptionIndex`=0) OR (`MenuId`=16664 AND `OptionIndex`=0) OR (`MenuId`=16662 AND `OptionIndex`=0) OR (`MenuId`=16792 AND `OptionIndex`=0) OR (`MenuId`=16793 AND `OptionIndex`=0) OR (`MenuId`=17203 AND `OptionIndex`=0) OR (`MenuId`=16777 AND `OptionIndex`=1) OR (`MenuId`=18677 AND `OptionIndex`=0) OR (`MenuId`=17330 AND `OptionIndex`=1) OR (`MenuId`=14044 AND `OptionIndex`=1) OR (`MenuId`=14043 AND `OptionIndex`=1) OR (`MenuId`=14046 AND `OptionIndex`=1) OR (`MenuId`=14667 AND `OptionIndex`=0) OR (`MenuId`=14666 AND `OptionIndex`=0) OR (`MenuId`=14665 AND `OptionIndex`=0) OR (`MenuId`=14664 AND `OptionIndex`=0) OR (`MenuId`=14044 AND `OptionIndex`=2) OR (`MenuId`=13733 AND `OptionIndex`=0) OR (`MenuId`=13714 AND `OptionIndex`=1) OR (`MenuId`=13713 AND `OptionIndex`=0) OR (`MenuId`=13494 AND `OptionIndex`=0) OR (`MenuId`=13440 AND `OptionIndex`=0) OR (`MenuId`=13455 AND `OptionIndex`=1) OR (`MenuId`=15091 AND `OptionIndex`=0) OR (`MenuId`=13535 AND `OptionIndex`=0) OR (`MenuId`=14333 AND `OptionIndex`=0) OR (`MenuId`=13454 AND `OptionIndex`=0) OR (`MenuId`=13446 AND `OptionIndex`=0) OR (`MenuId`=13491 AND `OptionIndex`=1) OR (`MenuId`=13384 AND `OptionIndex`=0) OR (`MenuId`=13419 AND `OptionIndex`=0) OR (`MenuId`=13403 AND `OptionIndex`=0) OR (`MenuId`=13351 AND `OptionIndex`=2) OR (`MenuId`=13387 AND `OptionIndex`=2) OR (`MenuId`=13353 AND `OptionIndex`=0) OR (`MenuId`=13355 AND `OptionIndex`=0) OR (`MenuId`=13354 AND `OptionIndex`=0) OR (`MenuId`=13353 AND `OptionIndex`=1) OR (`MenuId`=13332 AND `OptionIndex`=0) OR (`MenuId`=13593 AND `OptionIndex`=0) OR (`MenuId`=13338 AND `OptionIndex`=0) OR (`MenuId`=13594 AND `OptionIndex`=0) OR (`MenuId`=15156 AND `OptionIndex`=0) OR (`MenuId`=13653 AND `OptionIndex`=11) OR (`MenuId`=13663 AND `OptionIndex`=0) OR (`MenuId`=13653 AND `OptionIndex`=9) OR (`MenuId`=13662 AND `OptionIndex`=0) OR (`MenuId`=13653 AND `OptionIndex`=8) OR (`MenuId`=13661 AND `OptionIndex`=0) OR (`MenuId`=13653 AND `OptionIndex`=7) OR (`MenuId`=13660 AND `OptionIndex`=0) OR (`MenuId`=13653 AND `OptionIndex`=6) OR (`MenuId`=13659 AND `OptionIndex`=0) OR (`MenuId`=13653 AND `OptionIndex`=5) OR (`MenuId`=13658 AND `OptionIndex`=0) OR (`MenuId`=13653 AND `OptionIndex`=4) OR (`MenuId`=13657 AND `OptionIndex`=0) OR (`MenuId`=13653 AND `OptionIndex`=3) OR (`MenuId`=13656 AND `OptionIndex`=0) OR (`MenuId`=13653 AND `OptionIndex`=2) OR (`MenuId`=13655 AND `OptionIndex`=0) OR (`MenuId`=13653 AND `OptionIndex`=1) OR (`MenuId`=13654 AND `OptionIndex`=0) OR (`MenuId`=13653 AND `OptionIndex`=0) OR (`MenuId`=13445 AND `OptionIndex`=2) OR (`MenuId`=13476 AND `OptionIndex`=10) OR (`MenuId`=13470 AND `OptionIndex`=2) OR (`MenuId`=13476 AND `OptionIndex`=9) OR (`MenuId`=13476 AND `OptionIndex`=8) OR (`MenuId`=13476 AND `OptionIndex`=7) OR (`MenuId`=13476 AND `OptionIndex`=6) OR (`MenuId`=13476 AND `OptionIndex`=5) OR (`MenuId`=13476 AND `OptionIndex`=3) OR (`MenuId`=13476 AND `OptionIndex`=2) OR (`MenuId`=13476 AND `OptionIndex`=1) OR (`MenuId`=13476 AND `OptionIndex`=0) OR (`MenuId`=13470 AND `OptionIndex`=1) OR (`MenuId`=13470 AND `OptionIndex`=0) OR (`MenuId`=13641 AND `OptionIndex`=0) OR (`MenuId`=13642 AND `OptionIndex`=0) OR (`MenuId`=13445 AND `OptionIndex`=1) OR (`MenuId`=15579 AND `OptionIndex`=11) OR (`MenuId`=15579 AND `OptionIndex`=10) OR (`MenuId`=13750 AND `OptionIndex`=0) OR (`MenuId`=13742 AND `OptionIndex`=0) OR (`MenuId`=13741 AND `OptionIndex`=0) OR (`MenuId`=13740 AND `OptionIndex`=0) OR (`MenuId`=14934 AND `OptionIndex`=0) OR (`MenuId`=13237 AND `OptionIndex`=0) OR (`MenuId`=12315 AND `OptionIndex`=0) OR (`MenuId`=12314 AND `OptionIndex`=0) OR (`MenuId`=12286 AND `OptionIndex`=0) OR (`MenuId`=12285 AND `OptionIndex`=0) OR (`MenuId`=12284 AND `OptionIndex`=0) OR (`MenuId`=12290 AND `OptionIndex`=0) OR (`MenuId`=12289 AND `OptionIndex`=0) OR (`MenuId`=12288 AND `OptionIndex`=0) OR (`MenuId`=12318 AND `OptionIndex`=0) OR (`MenuId`=12317 AND `OptionIndex`=0) OR (`MenuId`=11581 AND `OptionIndex`=0) OR (`MenuId`=11580 AND `OptionIndex`=0) OR (`MenuId`=11579 AND `OptionIndex`=0) OR (`MenuId`=11578 AND `OptionIndex`=0) OR (`MenuId`=11577 AND `OptionIndex`=0) OR (`MenuId`=11576 AND `OptionIndex`=0) OR (`MenuId`=11575 AND `OptionIndex`=0) OR (`MenuId`=11574 AND `OptionIndex`=0) OR (`MenuId`=11592 AND `OptionIndex`=0) OR (`MenuId`=11591 AND `OptionIndex`=2) OR (`MenuId`=11590 AND `OptionIndex`=2) OR (`MenuId`=11589 AND `OptionIndex`=2) OR (`MenuId`=11588 AND `OptionIndex`=1) OR (`MenuId`=11593 AND `OptionIndex`=1) OR (`MenuId`=11586 AND `OptionIndex`=0) OR (`MenuId`=11591 AND `OptionIndex`=0) OR (`MenuId`=11590 AND `OptionIndex`=0) OR (`MenuId`=11589 AND `OptionIndex`=0) OR (`MenuId`=11588 AND `OptionIndex`=0) OR (`MenuId`=11593 AND `OptionIndex`=0) OR (`MenuId`=11591 AND `OptionIndex`=1) OR (`MenuId`=11590 AND `OptionIndex`=1) OR (`MenuId`=11589 AND `OptionIndex`=1) OR (`MenuId`=11588 AND `OptionIndex`=2) OR (`MenuId`=11593 AND `OptionIndex`=2) OR (`MenuId`=11351 AND `OptionIndex`=0) OR (`MenuId`=11352 AND `OptionIndex`=0) OR (`MenuId`=18268 AND `OptionIndex`=1) OR (`MenuId`=16467 AND `OptionIndex`=0) OR (`MenuId`=16721 AND `OptionIndex`=0) OR (`MenuId`=16940 AND `OptionIndex`=1) OR (`MenuId`=15997 AND `OptionIndex`=3) OR (`MenuId`=15997 AND `OptionIndex`=1) OR (`MenuId`=15997 AND `OptionIndex`=2) OR (`MenuId`=14806 AND `OptionIndex`=0) OR (`MenuId`=14690 AND `OptionIndex`=0) OR (`MenuId`=15152 AND `OptionIndex`=8) OR (`MenuId`=15107 AND `OptionIndex`=0) OR (`MenuId`=14518 AND `OptionIndex`=0) OR (`MenuId`=14346 AND `OptionIndex`=1) OR (`MenuId`=14346 AND `OptionIndex`=0) OR (`MenuId`=14523 AND `OptionIndex`=0) OR (`MenuId`=14522 AND `OptionIndex`=1) OR (`MenuId`=14522 AND `OptionIndex`=0) OR (`MenuId`=14514 AND `OptionIndex`=0) OR (`MenuId`=14347 AND `OptionIndex`=1) OR (`MenuId`=14347 AND `OptionIndex`=0) OR (`MenuId`=14348 AND `OptionIndex`=2) OR (`MenuId`=14348 AND `OptionIndex`=1) OR (`MenuId`=14508 AND `OptionIndex`=0) OR (`MenuId`=14507 AND `OptionIndex`=1) OR (`MenuId`=14507 AND `OptionIndex`=0) OR (`MenuId`=14505 AND `OptionIndex`=0) OR (`MenuId`=14350 AND `OptionIndex`=1) OR (`MenuId`=14350 AND `OptionIndex`=0) OR (`MenuId`=14503 AND `OptionIndex`=0) OR (`MenuId`=14349 AND `OptionIndex`=1) OR (`MenuId`=14349 AND `OptionIndex`=0) OR (`MenuId`=14351 AND `OptionIndex`=1) OR (`MenuId`=14351 AND `OptionIndex`=0) OR (`MenuId`=14520 AND `OptionIndex`=0) OR (`MenuId`=14519 AND `OptionIndex`=1) OR (`MenuId`=14519 AND `OptionIndex`=0) OR (`MenuId`=14692 AND `OptionIndex`=2) OR (`MenuId`=14751 AND `OptionIndex`=0) OR (`MenuId`=14692 AND `OptionIndex`=1) OR (`MenuId`=14752 AND `OptionIndex`=0) OR (`MenuId`=14692 AND `OptionIndex`=0) OR (`MenuId`=14558 AND `OptionIndex`=11) OR (`MenuId`=14693 AND `OptionIndex`=22) OR (`MenuId`=14771 AND `OptionIndex`=0) OR (`MenuId`=14693 AND `OptionIndex`=21) OR (`MenuId`=14750 AND `OptionIndex`=0) OR (`MenuId`=14693 AND `OptionIndex`=20) OR (`MenuId`=14749 AND `OptionIndex`=0) OR (`MenuId`=14693 AND `OptionIndex`=19) OR (`MenuId`=14748 AND `OptionIndex`=0) OR (`MenuId`=14693 AND `OptionIndex`=18) OR (`MenuId`=14747 AND `OptionIndex`=0) OR (`MenuId`=14693 AND `OptionIndex`=17) OR (`MenuId`=14746 AND `OptionIndex`=0) OR (`MenuId`=14693 AND `OptionIndex`=16) OR (`MenuId`=14745 AND `OptionIndex`=0) OR (`MenuId`=14693 AND `OptionIndex`=15) OR (`MenuId`=14744 AND `OptionIndex`=0) OR (`MenuId`=14693 AND `OptionIndex`=14) OR (`MenuId`=14743 AND `OptionIndex`=0) OR (`MenuId`=14693 AND `OptionIndex`=13) OR (`MenuId`=14742 AND `OptionIndex`=0) OR (`MenuId`=14693 AND `OptionIndex`=12) OR (`MenuId`=14770 AND `OptionIndex`=0) OR (`MenuId`=14693 AND `OptionIndex`=11) OR (`MenuId`=14741 AND `OptionIndex`=0) OR (`MenuId`=14693 AND `OptionIndex`=10) OR (`MenuId`=14740 AND `OptionIndex`=0) OR (`MenuId`=14693 AND `OptionIndex`=9) OR (`MenuId`=14739 AND `OptionIndex`=0) OR (`MenuId`=14693 AND `OptionIndex`=8) OR (`MenuId`=14738 AND `OptionIndex`=0) OR (`MenuId`=14693 AND `OptionIndex`=7) OR (`MenuId`=14737 AND `OptionIndex`=0) OR (`MenuId`=14693 AND `OptionIndex`=6) OR (`MenuId`=14736 AND `OptionIndex`=0) OR (`MenuId`=14693 AND `OptionIndex`=5) OR (`MenuId`=14735 AND `OptionIndex`=0) OR (`MenuId`=14693 AND `OptionIndex`=4) OR (`MenuId`=14697 AND `OptionIndex`=0) OR (`MenuId`=14693 AND `OptionIndex`=3) OR (`MenuId`=14696 AND `OptionIndex`=0) OR (`MenuId`=14693 AND `OptionIndex`=2) OR (`MenuId`=14695 AND `OptionIndex`=0) OR (`MenuId`=14693 AND `OptionIndex`=1) OR (`MenuId`=14694 AND `OptionIndex`=0) OR (`MenuId`=14693 AND `OptionIndex`=0) OR (`MenuId`=14558 AND `OptionIndex`=10) OR (`MenuId`=14691 AND `OptionIndex`=0) OR (`MenuId`=14558 AND `OptionIndex`=9) OR (`MenuId`=14772 AND `OptionIndex`=13) OR (`MenuId`=14785 AND `OptionIndex`=0) OR (`MenuId`=14772 AND `OptionIndex`=12) OR (`MenuId`=14784 AND `OptionIndex`=0) OR (`MenuId`=14772 AND `OptionIndex`=11) OR (`MenuId`=14783 AND `OptionIndex`=0) OR (`MenuId`=14772 AND `OptionIndex`=10) OR (`MenuId`=14782 AND `OptionIndex`=0) OR (`MenuId`=14772 AND `OptionIndex`=9) OR (`MenuId`=14781 AND `OptionIndex`=0) OR (`MenuId`=14772 AND `OptionIndex`=8) OR (`MenuId`=14780 AND `OptionIndex`=0) OR (`MenuId`=14772 AND `OptionIndex`=7) OR (`MenuId`=14778 AND `OptionIndex`=0) OR (`MenuId`=14772 AND `OptionIndex`=5) OR (`MenuId`=14776 AND `OptionIndex`=0) OR (`MenuId`=14772 AND `OptionIndex`=4) OR (`MenuId`=14775 AND `OptionIndex`=0) OR (`MenuId`=14772 AND `OptionIndex`=3) OR (`MenuId`=14831 AND `OptionIndex`=0) OR (`MenuId`=14772 AND `OptionIndex`=2) OR (`MenuId`=14774 AND `OptionIndex`=0) OR (`MenuId`=14772 AND `OptionIndex`=1) OR (`MenuId`=14773 AND `OptionIndex`=0) OR (`MenuId`=14772 AND `OptionIndex`=0) OR (`MenuId`=14558 AND `OptionIndex`=7) OR (`MenuId`=14769 AND `OptionIndex`=15) OR (`MenuId`=14768 AND `OptionIndex`=0) OR (`MenuId`=14769 AND `OptionIndex`=14) OR (`MenuId`=14767 AND `OptionIndex`=0) OR (`MenuId`=14769 AND `OptionIndex`=13) OR (`MenuId`=14766 AND `OptionIndex`=0) OR (`MenuId`=14769 AND `OptionIndex`=12) OR (`MenuId`=14765 AND `OptionIndex`=0) OR (`MenuId`=14769 AND `OptionIndex`=11) OR (`MenuId`=14764 AND `OptionIndex`=0) OR (`MenuId`=14769 AND `OptionIndex`=10) OR (`MenuId`=14763 AND `OptionIndex`=0) OR (`MenuId`=14769 AND `OptionIndex`=9) OR (`MenuId`=14761 AND `OptionIndex`=0) OR (`MenuId`=14769 AND `OptionIndex`=8) OR (`MenuId`=14762 AND `OptionIndex`=0) OR (`MenuId`=14769 AND `OptionIndex`=7) OR (`MenuId`=14754 AND `OptionIndex`=0) OR (`MenuId`=14769 AND `OptionIndex`=6) OR (`MenuId`=14760 AND `OptionIndex`=0) OR (`MenuId`=14769 AND `OptionIndex`=5) OR (`MenuId`=14759 AND `OptionIndex`=0) OR (`MenuId`=14769 AND `OptionIndex`=4) OR (`MenuId`=14758 AND `OptionIndex`=0) OR (`MenuId`=14769 AND `OptionIndex`=3) OR (`MenuId`=14756 AND `OptionIndex`=0) OR (`MenuId`=14769 AND `OptionIndex`=2) OR (`MenuId`=14757 AND `OptionIndex`=0) OR (`MenuId`=14769 AND `OptionIndex`=1) OR (`MenuId`=14755 AND `OptionIndex`=0) OR (`MenuId`=14769 AND `OptionIndex`=0) OR (`MenuId`=14558 AND `OptionIndex`=6) OR (`MenuId`=14689 AND `OptionIndex`=0) OR (`MenuId`=14558 AND `OptionIndex`=5) OR (`MenuId`=14688 AND `OptionIndex`=0) OR (`MenuId`=14558 AND `OptionIndex`=4) OR (`MenuId`=14686 AND `OptionIndex`=0) OR (`MenuId`=14558 AND `OptionIndex`=2) OR (`MenuId`=14561 AND `OptionIndex`=0) OR (`MenuId`=15152 AND `OptionIndex`=1) OR (`MenuId`=13692 AND `OptionIndex`=0) OR (`MenuId`=13852 AND `OptionIndex`=0) OR (`MenuId`=13671 AND `OptionIndex`=1) OR (`MenuId`=13851 AND `OptionIndex`=0) OR (`MenuId`=13671 AND `OptionIndex`=0) OR (`MenuId`=14530 AND `OptionIndex`=0) OR (`MenuId`=14532 AND `OptionIndex`=0) OR (`MenuId`=13396 AND `OptionIndex`=1) OR (`MenuId`=13070 AND `OptionIndex`=2) OR (`MenuId`=13105 AND `OptionIndex`=0) OR (`MenuId`=13427 AND `OptionIndex`=5) OR (`MenuId`=13286 AND `OptionIndex`=1) OR (`MenuId`=13110 AND `OptionIndex`=0) OR (`MenuId`=14918 AND `OptionIndex`=0) OR (`MenuId`=14912 AND `OptionIndex`=0) OR (`MenuId`=14913 AND `OptionIndex`=0) OR (`MenuId`=14971 AND `OptionIndex`=1) OR (`MenuId`=12059 AND `OptionIndex`=0) OR (`MenuId`=12456 AND `OptionIndex`=1) OR (`MenuId`=12455 AND `OptionIndex`=0) OR (`MenuId`=12451 AND `OptionIndex`=0) OR (`MenuId`=12456 AND `OptionIndex`=2) OR (`MenuId`=12455 AND `OptionIndex`=2) OR (`MenuId`=12455 AND `OptionIndex`=1) OR (`MenuId`=12456 AND `OptionIndex`=0) OR (`MenuId`=12243 AND `OptionIndex`=6) OR (`MenuId`=12243 AND `OptionIndex`=5) OR (`MenuId`=12243 AND `OptionIndex`=4) OR (`MenuId`=12243 AND `OptionIndex`=3) OR (`MenuId`=12243 AND `OptionIndex`=2) OR (`MenuId`=18488 AND `OptionIndex`=1) OR (`MenuId`=18337 AND `OptionIndex`=2) OR (`MenuId`=18337 AND `OptionIndex`=1) OR (`MenuId`=18337 AND `OptionIndex`=0) OR (`MenuId`=18226 AND `OptionIndex`=0);
INSERT INTO `gossip_menu_option_action` (`MenuId`, `OptionIndex`, `ActionMenuId`, `ActionPoiId`) VALUES
(18335, 1, 18416, 0),
(18335, 0, 18334, 0),
(18333, 0, 18332, 0),
(18331, 2, 18415, 0),
(18331, 1, 18332, 0),
(18331, 0, 18330, 0),
(18412, 1, 18413, 0),
(18228, 0, 18227, 0),
(16353, 0, 16354, 0),
(16597, 0, 16160, 0),
(18275, 0, 18276, 0),
(17334, 11, 17336, 5047),
(17372, 4, 17375, 4492),
(17334, 10, 17372, 0),
(17372, 2, 17373, 4473),
(17372, 3, 17374, 4472),
(17372, 1, 17337, 4468),
(17372, 0, 17371, 4469),
(17334, 9, 17336, 4467),
(17334, 8, 17370, 4474),
(17349, 12, 17367, 4481),
(17334, 7, 17349, 0),
(17349, 14, 17369, 4489),
(17349, 13, 17368, 4487),
(17349, 11, 17366, 4488),
(17349, 10, 17365, 4482),
(17349, 9, 17364, 4490),
(17349, 8, 17363, 4479),
(17349, 7, 17362, 4470),
(17349, 6, 17361, 4483),
(17349, 5, 17356, 4484),
(17349, 4, 17355, 4497),
(17349, 3, 17353, 4477),
(17349, 2, 17352, 4480),
(17349, 1, 17351, 4491),
(17349, 0, 17350, 4478),
(17334, 6, 17335, 4466),
(17348, 2, 17347, 4495),
(17334, 5, 17348, 0),
(17348, 1, 17346, 4494),
(17348, 0, 17345, 4493),
(17344, 2, 17343, 4471),
(17334, 4, 17344, 0),
(17344, 1, 17342, 4475),
(17344, 0, 17341, 4496),
(17334, 3, 17340, 4476),
(17334, 2, 17339, 4485),
(17334, 1, 17338, 4486),
(17334, 0, 17337, 4468),
(16236, 0, 16258, 0),
(16872, 4, 16868, 0),
(16526, 1, 16564, 0),
(16526, 0, 16527, 0),
(17000, 4, 18564, 0),
(17005, 0, 17000, 0),
(17000, 3, 17005, 0),
(16613, 0, 16812, 0),
(13892, 0, 13893, 0),
(13893, 0, 13892, 0),
(13462, 3, 13467, 0),
(13462, 1, 13464, 0),
(13464, 2, 13462, 0),
(13301, 4, 13437, 0),
(13748, 0, 13745, 0),
(13747, 0, 13748, 0),
(13746, 0, 13747, 0),
(13745, 0, 13746, 0),
(12115, 0, 12116, 0),
(12114, 0, 12115, 0),
(12113, 0, 12114, 0),
(12136, 0, 12135, 0),
(12137, 0, 12136, 0),
(12138, 0, 12137, 0),
(11514, 0, 11513, 0),
(11510, 0, 11514, 0),
(11511, 0, 11510, 0),
(11508, 0, 11511, 0),
(11509, 0, 11508, 0),
(11489, 0, 11509, 0),
(16664, 0, 16665, 0),
(16662, 0, 16664, 0),
(16792, 0, 16791, 0),
(16793, 0, 16792, 0),
(17203, 0, 16777, 0),
(16777, 1, 17203, 0),
(18677, 0, 18779, 0),
(17330, 1, 17354, 0),
(14044, 1, 14053, 0),
(14043, 1, 14049, 0),
(14046, 1, 14055, 0),
(14667, 0, 14668, 0),
(14666, 0, 14667, 0),
(14665, 0, 14666, 0),
(14664, 0, 14665, 0),
(14044, 2, 14664, 0),
(13733, 0, 13735, 0),
(13714, 1, 13713, 0),
(13713, 0, 13714, 0),
(13494, 0, 13493, 0),
(13440, 0, 13494, 0),
(13455, 1, 15139, 0),
(15091, 0, 15092, 0),
(13535, 0, 15091, 0),
(14333, 0, 14334, 0),
(13454, 0, 13498, 0),
(13446, 0, 13496, 0),
(13491, 1, 13495, 0),
(13384, 0, 13419, 0),
(13419, 0, 13384, 0),
(13403, 0, 13404, 0),
(13351, 2, 13403, 0),
(13387, 2, 15141, 0),
(13353, 0, 13354, 0),
(13355, 0, 13354, 0),
(13354, 0, 13355, 0),
(13353, 1, 13355, 0),
(13332, 0, 13600, 0),
(13593, 0, 13601, 0),
(13338, 0, 13602, 0),
(13594, 0, 13597, 0),
(15156, 0, 13653, 0),
(13653, 11, 15156, 0),
(13663, 0, 13653, 0),
(13653, 9, 13663, 0),
(13662, 0, 13653, 0),
(13653, 8, 13662, 0),
(13661, 0, 13653, 0),
(13653, 7, 13661, 0),
(13660, 0, 13653, 0),
(13653, 6, 13660, 0),
(13659, 0, 13653, 0),
(13653, 5, 13659, 0),
(13658, 0, 13653, 0),
(13653, 4, 13658, 0),
(13657, 0, 13653, 0),
(13653, 3, 13657, 0),
(13656, 0, 13653, 0),
(13653, 2, 13656, 0),
(13655, 0, 13653, 0),
(13653, 1, 13655, 0),
(13654, 0, 13653, 0),
(13653, 0, 13654, 0),
(13445, 2, 13653, 0),
(13476, 10, 13475, 0),
(13470, 2, 13476, 0),
(13476, 9, 13485, 2731),
(13476, 8, 13484, 2729),
(13476, 7, 13483, 2727),
(13476, 6, 13482, 2734),
(13476, 5, 13481, 2730),
(13476, 3, 13480, 2733),
(13476, 2, 13479, 2732),
(13476, 1, 13477, 2726),
(13476, 0, 13478, 2728),
(13470, 1, 13567, 0),
(13470, 0, 13469, 0),
(13641, 0, 13640, 0),
(13642, 0, 13641, 0),
(13445, 1, 14403, 0),
(15579, 11, 15597, 2928),
(15579, 10, 15596, 0),
(13750, 0, 13751, 0),
(13742, 0, 13740, 0),
(13741, 0, 13742, 0),
(13740, 0, 13741, 0),
(14934, 0, 14936, 0),
(13237, 0, 13251, 0),
(12315, 0, 12316, 0),
(12314, 0, 12315, 0),
(12286, 0, 12287, 0),
(12285, 0, 12286, 0),
(12284, 0, 12285, 0),
(12290, 0, 12291, 0),
(12289, 0, 12290, 0),
(12288, 0, 12289, 0),
(12318, 0, 12319, 0),
(12317, 0, 12318, 0),
(11581, 0, 11582, 0),
(11580, 0, 11581, 0),
(11579, 0, 11580, 0),
(11578, 0, 11579, 0),
(11577, 0, 11578, 0),
(11576, 0, 11577, 0),
(11575, 0, 11576, 0),
(11574, 0, 11575, 0),
(11592, 0, 11594, 0),
(11591, 2, 11592, 0),
(11590, 2, 11591, 0),
(11589, 2, 11590, 0),
(11588, 1, 11589, 0),
(11593, 1, 11588, 0),
(11586, 0, 11593, 0),
(11591, 0, 11592, 0),
(11590, 0, 11591, 0),
(11589, 0, 11590, 0),
(11588, 0, 11589, 0),
(11593, 0, 11588, 0),
(11591, 1, 11592, 0),
(11590, 1, 11591, 0),
(11589, 1, 11590, 0),
(11588, 2, 11589, 0),
(11593, 2, 11588, 0),
(11351, 0, 11350, 0),
(11352, 0, 11351, 0),
(18268, 1, 18292, 0),
(16467, 0, 16483, 0),
(16721, 0, 16722, 0),
(16940, 1, 16942, 0),
(15997, 3, 16442, 0),
(15997, 1, 16395, 0),
(15997, 2, 16396, 0),
(14806, 0, 14805, 0),
(14690, 0, 14833, 0),
(15152, 8, 14690, 2800),
(15107, 0, 15105, 0),
(14518, 0, 14794, 0),
(14346, 1, 14518, 0),
(14346, 0, 14517, 0),
(14523, 0, 14793, 0),
(14522, 1, 14523, 0),
(14522, 0, 14524, 0),
(14514, 0, 14792, 0),
(14347, 1, 14514, 0),
(14347, 0, 14515, 0),
(14348, 2, 14512, 0),
(14348, 1, 14513, 0),
(14508, 0, 14791, 2886),
(14507, 1, 14508, 0),
(14507, 0, 14509, 0),
(14505, 0, 14790, 0),
(14350, 1, 14505, 0),
(14350, 0, 14506, 0),
(14503, 0, 14789, 2839),
(14349, 1, 14503, 0),
(14349, 0, 14502, 0),
(14351, 1, 14495, 0),
(14351, 0, 14494, 0),
(14520, 0, 14788, 2844),
(14519, 1, 14520, 0),
(14519, 0, 14521, 0),
(14692, 2, 14558, 0),
(14751, 0, 14692, 0),
(14692, 1, 14751, 0),
(14752, 0, 14692, 0),
(14692, 0, 14752, 0),
(14558, 11, 14692, 0),
(14693, 22, 14558, 0),
(14771, 0, 14693, 0),
(14693, 21, 14771, 2796),
(14750, 0, 14693, 0);

INSERT INTO `gossip_menu_option_action` (`MenuId`, `OptionIndex`, `ActionMenuId`, `ActionPoiId`) VALUES
(14693, 20, 14750, 2956),
(14749, 0, 14693, 0),
(14693, 19, 14749, 2858),
(14748, 0, 14693, 0),
(14693, 18, 14748, 2798),
(14747, 0, 14693, 0),
(14693, 17, 14747, 2807),
(14746, 0, 14693, 0),
(14693, 16, 14746, 2815),
(14745, 0, 14693, 0),
(14693, 15, 14745, 2857),
(14744, 0, 14693, 0),
(14693, 14, 14744, 2811),
(14743, 0, 14693, 0),
(14693, 13, 14743, 2802),
(14742, 0, 14693, 0),
(14693, 12, 14742, 2803),
(14770, 0, 14693, 0),
(14693, 11, 14770, 2797),
(14741, 0, 14693, 0),
(14693, 10, 14741, 2812),
(14740, 0, 14693, 0),
(14693, 9, 14740, 2856),
(14739, 0, 14693, 0),
(14693, 8, 14739, 2810),
(14738, 0, 14693, 0),
(14693, 7, 14738, 2820),
(14737, 0, 14693, 0),
(14693, 6, 14737, 2808),
(14736, 0, 14693, 0),
(14693, 5, 14736, 2801),
(14735, 0, 14693, 0),
(14693, 4, 14735, 2805),
(14697, 0, 14693, 0),
(14693, 3, 14697, 2813),
(14696, 0, 14693, 0),
(14693, 2, 14696, 2814),
(14695, 0, 14693, 0),
(14693, 1, 14695, 2806),
(14694, 0, 14693, 0),
(14693, 0, 14694, 2804),
(14558, 10, 14693, 0),
(14691, 0, 14558, 0),
(14558, 9, 14691, 2795),
(14772, 13, 14558, 0),
(14785, 0, 14772, 0),
(14772, 12, 14785, 2845),
(14784, 0, 14772, 0),
(14772, 11, 14784, 2881),
(14783, 0, 14772, 0),
(14772, 10, 14783, 2886),
(14782, 0, 14772, 0),
(14772, 9, 14782, 2844),
(14781, 0, 14772, 0),
(14772, 8, 14781, 2843),
(14780, 0, 14772, 0),
(14772, 7, 14780, 2842),
(14778, 0, 14772, 0),
(14772, 5, 14778, 2840),
(14776, 0, 14772, 0),
(14772, 4, 14776, 2839),
(14775, 0, 14772, 0),
(14772, 3, 14775, 2837),
(14831, 0, 14772, 0),
(14772, 2, 14831, 2838),
(14774, 0, 14772, 0),
(14772, 1, 14774, 2882),
(14773, 0, 14772, 0),
(14772, 0, 14773, 2835),
(14558, 7, 14772, 0),
(14769, 15, 14558, 0),
(14768, 0, 14769, 0),
(14769, 14, 14768, 2833),
(14767, 0, 14769, 0),
(14769, 13, 14767, 2827),
(14766, 0, 14769, 0),
(14769, 12, 14766, 2832),
(14765, 0, 14769, 0),
(14769, 11, 14765, 0),
(14764, 0, 14769, 0),
(14769, 10, 14764, 2831),
(14763, 0, 14769, 0),
(14769, 9, 14763, 2830),
(14761, 0, 14769, 0),
(14769, 8, 14761, 0),
(14762, 0, 14769, 0),
(14769, 7, 14762, 2829),
(14754, 0, 14769, 0),
(14769, 6, 14754, 2828),
(14760, 0, 14769, 0),
(14769, 5, 14760, 2826),
(14759, 0, 14769, 0),
(14769, 4, 14759, 2825),
(14758, 0, 14769, 0),
(14769, 3, 14758, 2824),
(14756, 0, 14769, 0),
(14769, 2, 14756, 2823),
(14757, 0, 14769, 0),
(14769, 1, 14757, 2822),
(14755, 0, 14769, 0),
(14769, 0, 14755, 2821),
(14558, 6, 14769, 0),
(14689, 0, 14558, 0),
(14558, 5, 14689, 2819),
(14688, 0, 14558, 0),
(14558, 4, 14688, 2794),
(14686, 0, 14558, 0),
(14558, 2, 14686, 2793),
(14561, 0, 14558, 0),
(15152, 1, 14561, 2792),
(13692, 0, 13691, 0),
(13852, 0, 13671, 0),
(13671, 1, 13852, 0),
(13851, 0, 13671, 0),
(13671, 0, 13851, 0),
(14530, 0, 14531, 0),
(14532, 0, 14530, 0),
(13396, 1, 13401, 0),
(13070, 2, 13072, 0),
(13105, 0, 13106, 0),
(13427, 5, 14653, 0),
(13286, 1, 13525, 0),
(13110, 0, 13150, 0),
(14918, 0, 14919, 0),
(14912, 0, 14911, 0),
(14913, 0, 14912, 0),
(14971, 1, 15111, 0),
(12059, 0, 12060, 0),
(12456, 1, 12457, 0),
(12455, 0, 12456, 0),
(12451, 0, 12455, 0),
(12456, 2, 12457, 0),
(12455, 2, 12456, 0),
(12455, 1, 12456, 0),
(12456, 0, 12457, 0),
(12243, 6, 20916, 5212),
(12243, 5, 20920, 5214),
(12243, 4, 20917, 2518),
(12243, 3, 20922, 5216),
(12243, 2, 20919, 5213),
(18488, 1, 18712, 0),
(18337, 2, 18418, 0),
(18337, 1, 18417, 0),
(18337, 0, 18336, 0),
(18226, 0, 18225, 0);

UPDATE `gossip_menu_option_action` SET `ActionPoiId`=93 WHERE (`MenuId`=421 AND `OptionIndex`=5);
UPDATE `gossip_menu_option_action` SET `ActionPoiId`=108 WHERE (`MenuId`=421 AND `OptionIndex`=4);
UPDATE `gossip_menu_option_action` SET `ActionPoiId`=68 WHERE (`MenuId`=421 AND `OptionIndex`=3);
UPDATE `gossip_menu_option_action` SET `ActionPoiId`=94 WHERE (`MenuId`=421 AND `OptionIndex`=2);
UPDATE `gossip_menu_option_action` SET `ActionPoiId`=2424 WHERE (`MenuId`=421 AND `OptionIndex`=1);
UPDATE `gossip_menu_option_action` SET `ActionPoiId`=91 WHERE (`MenuId`=421 AND `OptionIndex`=0);
UPDATE `gossip_menu_option_action` SET `ActionPoiId`=5215 WHERE (`MenuId`=12243 AND `OptionIndex`=1);
UPDATE `gossip_menu_option_action` SET `ActionPoiId`=532 WHERE (`MenuId`=12243 AND `OptionIndex`=0);
UPDATE `gossip_menu_option_action` SET `ActionPoiId`=2420 WHERE (`MenuId`=11845 AND `OptionIndex`=5);
UPDATE `gossip_menu_option_action` SET `ActionPoiId`=2110 WHERE (`MenuId`=11845 AND `OptionIndex`=4);
UPDATE `gossip_menu_option_action` SET `ActionPoiId`=2421 WHERE (`MenuId`=11845 AND `OptionIndex`=3);
UPDATE `gossip_menu_option_action` SET `ActionPoiId`=72 WHERE (`MenuId`=11845 AND `OptionIndex`=2);
UPDATE `gossip_menu_option_action` SET `ActionPoiId`=532 WHERE (`MenuId`=11845 AND `OptionIndex`=1);
UPDATE `gossip_menu_option_action` SET `ActionPoiId`=1467 WHERE (`MenuId`=11845 AND `OptionIndex`=0);
UPDATE `gossip_menu_option_action` SET `ActionPoiId`=2419 WHERE (`MenuId`=11843 AND `OptionIndex`=1);
UPDATE `gossip_menu_option_action` SET `ActionPoiId`=529 WHERE (`MenuId`=11843 AND `OptionIndex`=0);
UPDATE `gossip_menu_option_action` SET `ActionPoiId`=2415 WHERE (`MenuId`=11841 AND `OptionIndex`=1);
UPDATE `gossip_menu_option_action` SET `ActionPoiId`=47 WHERE (`MenuId`=11841 AND `OptionIndex`=0);
UPDATE `gossip_menu_option_action` SET `ActionPoiId`=2416 WHERE (`MenuId`=11839 AND `OptionIndex`=1);
UPDATE `gossip_menu_option_action` SET `ActionPoiId`=527 WHERE (`MenuId`=11839 AND `OptionIndex`=0);
UPDATE `gossip_menu_option_action` SET `ActionPoiId`=2419 WHERE (`MenuId`=11843 AND `OptionIndex`=1);
UPDATE `gossip_menu_option_action` SET `ActionPoiId`=529 WHERE (`MenuId`=11843 AND `OptionIndex`=0);
UPDATE `gossip_menu_option_action` SET `ActionPoiId`=87 WHERE (`MenuId`=435 AND `OptionIndex`=9);
UPDATE `gossip_menu_option_action` SET `ActionPoiId`=67 WHERE (`MenuId`=435 AND `OptionIndex`=8);
UPDATE `gossip_menu_option_action` SET `ActionPoiId`=2766 WHERE (`MenuId`=401 AND `OptionIndex`=9);
UPDATE `gossip_menu_option_action` SET `ActionPoiId`=70 WHERE (`MenuId`=401 AND `OptionIndex`=8);
UPDATE `gossip_menu_option_action` SET `ActionPoiId`=75 WHERE (`MenuId`=401 AND `OptionIndex`=7);
UPDATE `gossip_menu_option_action` SET `ActionPoiId`=1986 WHERE (`MenuId`=401 AND `OptionIndex`=6);
UPDATE `gossip_menu_option_action` SET `ActionPoiId`=1986 WHERE (`MenuId`=401 AND `OptionIndex`=6);
UPDATE `gossip_menu_option_action` SET `ActionPoiId`=69 WHERE (`MenuId`=401 AND `OptionIndex`=5);
UPDATE `gossip_menu_option_action` SET `ActionPoiId`=73 WHERE (`MenuId`=401 AND `OptionIndex`=4);
UPDATE `gossip_menu_option_action` SET `ActionPoiId`=73 WHERE (`MenuId`=401 AND `OptionIndex`=3);
UPDATE `gossip_menu_option_action` SET `ActionPoiId`=71 WHERE (`MenuId`=401 AND `OptionIndex`=2);
UPDATE `gossip_menu_option_action` SET `ActionPoiId`=70 WHERE (`MenuId`=11855 AND `OptionIndex`=1);
UPDATE `gossip_menu_option_action` SET `ActionPoiId`=74 WHERE (`MenuId`=11855 AND `OptionIndex`=0);
UPDATE `gossip_menu_option_action` SET `ActionPoiId`=2417 WHERE (`MenuId`=401 AND `OptionIndex`=0);
UPDATE `gossip_menu_option_action` SET `ActionPoiId`=2202 WHERE (`MenuId`=435 AND `OptionIndex`=6);
UPDATE `gossip_menu_option_action` SET `ActionPoiId`=2415 WHERE (`MenuId`=11841 AND `OptionIndex`=1);
UPDATE `gossip_menu_option_action` SET `ActionPoiId`=47 WHERE (`MenuId`=11841 AND `OptionIndex`=0);
UPDATE `gossip_menu_option_action` SET `ActionPoiId`=2416 WHERE (`MenuId`=11839 AND `OptionIndex`=1);
UPDATE `gossip_menu_option_action` SET `ActionPoiId`=2714 WHERE (`MenuId`=435 AND `OptionIndex`=3);
UPDATE `gossip_menu_option_action` SET `ActionPoiId`=527 WHERE (`MenuId`=11839 AND `OptionIndex`=0);
UPDATE `gossip_menu_option_action` SET `ActionPoiId`=2714 WHERE (`MenuId`=435 AND `OptionIndex`=3);
UPDATE `gossip_menu_option_action` SET `ActionPoiId`=2714 WHERE (`MenuId`=435 AND `OptionIndex`=2);
UPDATE `gossip_menu_option_action` SET `ActionPoiId`=2887 WHERE (`MenuId`=435 AND `OptionIndex`=0);

UPDATE `gossip_menu_option_action` SET `ActionPoiId` = 71 WHERE `ActionPoiId` = 10533;
UPDATE `gossip_menu_option_action` SET `ActionPoiId` = 91 WHERE `ActionPoiId` = 10539;
UPDATE `gossip_menu_option_action` SET `ActionPoiId` = 75 WHERE `ActionPoiId` = 10537;
UPDATE `gossip_menu_option_action` SET `ActionPoiId` = 47 WHERE `ActionPoiId` = 10019;
UPDATE `gossip_menu_option_action` SET `ActionPoiId` = 87 WHERE `ActionPoiId` = 10553;
UPDATE `gossip_menu_option_action` SET `ActionPoiId` = 529 WHERE `ActionPoiId` = 10557;
UPDATE `gossip_menu_option_action` SET `ActionPoiId` = 108 WHERE `ActionPoiId` = 10543;
UPDATE `gossip_menu_option_action` SET `ActionPoiId` = 67 WHERE `ActionPoiId` = 10023;
UPDATE `gossip_menu_option_action` SET `ActionPoiId` = 527 WHERE `ActionPoiId` = 10018;
UPDATE `gossip_menu_option_action` SET `ActionPoiId` = 2421 WHERE `ActionPoiId` = 10562;
UPDATE `gossip_menu_option_action` SET `ActionPoiId` = 70 WHERE `ActionPoiId` = 10538;
UPDATE `gossip_menu_option_action` SET `ActionPoiId` = 72 WHERE `ActionPoiId` = 10561;
UPDATE `gossip_menu_option_action` SET `ActionPoiId` = 1467 WHERE `ActionPoiId` = 10559;
UPDATE `gossip_menu_option_action` SET `ActionPoiId` = 2202 WHERE `ActionPoiId` = 10030;
UPDATE `gossip_menu_option_action` SET `ActionPoiId` = 69 WHERE `ActionPoiId` = 10535;
UPDATE `gossip_menu_option_action` SET `ActionPoiId` = 5215 WHERE `ActionPoiId` = 10607;
UPDATE `gossip_menu_option_action` SET `ActionPoiId` = 68 WHERE `ActionPoiId` = 10542;
UPDATE `gossip_menu_option_action` SET `ActionPoiId` = 73 WHERE `ActionPoiId` = 10534;
UPDATE `gossip_menu_option_action` SET `ActionPoiId` = 2110 WHERE `ActionPoiId` = 10020;
UPDATE `gossip_menu_option_action` SET `ActionPoiId` = 2420 WHERE `ActionPoiId` = 10563;
UPDATE `gossip_menu_option_action` SET `ActionPoiId` = 94 WHERE `ActionPoiId` = 10541;
UPDATE `gossip_menu_option_action` SET `ActionPoiId` = 74 WHERE `ActionPoiId` = 10570;
UPDATE `gossip_menu_option_action` SET `ActionPoiId` = 532 WHERE `ActionPoiId` = 10560;
UPDATE `gossip_menu_option_action` SET `ActionPoiId` = 2419 WHERE `ActionPoiId` = 10558;
UPDATE `gossip_menu_option_action` SET `ActionPoiId` = 93 WHERE `ActionPoiId` = 10544;
UPDATE `gossip_menu_option_action` SET `ActionPoiId` = 2416 WHERE `ActionPoiId` = 10555;
UPDATE `gossip_menu_option_action` SET `ActionPoiId` = 1986 WHERE `ActionPoiId` = 10536;
UPDATE `gossip_menu_option_action` SET `ActionPoiId` = 2415 WHERE `ActionPoiId` = 10556;
UPDATE `gossip_menu_option_action` SET `ActionPoiId` = 2424 WHERE `ActionPoiId` = 10540;
UPDATE `gossip_menu_option_action` SET `ActionPoiId` = 2417 WHERE `ActionPoiId` = 10457;
UPDATE `gossip_menu_option_action` SET `ActionPoiId` = 2518 WHERE `ActionPoiId` = 10554;
UPDATE `gossip_menu_option_action` SET `ActionPoiId` = 10640 WHERE `ActionPoiId` = 10151;
UPDATE `gossip_menu_option_action` SET `ActionPoiId` = 10627 WHERE `ActionPoiId` = 10137;
UPDATE `gossip_menu_option_action` SET `ActionPoiId` = 10634 WHERE `ActionPoiId` = 10144;
UPDATE `gossip_menu_option_action` SET `ActionPoiId` = 10621 WHERE `ActionPoiId` = 10133;
UPDATE `gossip_menu_option_action` SET `ActionPoiId` = 10641 WHERE `ActionPoiId` = 10152;
UPDATE `gossip_menu_option_action` SET `ActionPoiId` = 10637 WHERE `ActionPoiId` = 10147;
UPDATE `gossip_menu_option_action` SET `ActionPoiId` = 10651 WHERE `ActionPoiId` = 10163;
UPDATE `gossip_menu_option_action` SET `ActionPoiId` = 10615 WHERE `ActionPoiId` = 10126;
UPDATE `gossip_menu_option_action` SET `ActionPoiId` = 10642 WHERE `ActionPoiId` = 10153;
UPDATE `gossip_menu_option_action` SET `ActionPoiId` = 10618 WHERE `ActionPoiId` = 10154;
UPDATE `gossip_menu_option_action` SET `ActionPoiId` = 10636 WHERE `ActionPoiId` = 10146;
UPDATE `gossip_menu_option_action` SET `ActionPoiId` = 10643 WHERE `ActionPoiId` = 10155;
UPDATE `gossip_menu_option_action` SET `ActionPoiId` = 10644 WHERE `ActionPoiId` = 10156;
UPDATE `gossip_menu_option_action` SET `ActionPoiId` = 10624 WHERE `ActionPoiId` = 10134;
UPDATE `gossip_menu_option_action` SET `ActionPoiId` = 10652 WHERE `ActionPoiId` = 10164;
UPDATE `gossip_menu_option_action` SET `ActionPoiId` = 10653 WHERE `ActionPoiId` = 10165;
UPDATE `gossip_menu_option_action` SET `ActionPoiId` = 10654 WHERE `ActionPoiId` = 10166;
UPDATE `gossip_menu_option_action` SET `ActionPoiId` = 10645 WHERE `ActionPoiId` = 10157;
UPDATE `gossip_menu_option_action` SET `ActionPoiId` = 10628 WHERE `ActionPoiId` = 10138;
UPDATE `gossip_menu_option_action` SET `ActionPoiId` = 10626 WHERE `ActionPoiId` = 10136;
UPDATE `gossip_menu_option_action` SET `ActionPoiId` = 10646 WHERE `ActionPoiId` = 10148;
UPDATE `gossip_menu_option_action` SET `ActionPoiId` = 10647 WHERE `ActionPoiId` = 10158;
UPDATE `gossip_menu_option_action` SET `ActionPoiId` = 10630 WHERE `ActionPoiId` = 10140;
UPDATE `gossip_menu_option_action` SET `ActionPoiId` = 10648 WHERE `ActionPoiId` = 10159;
UPDATE `gossip_menu_option_action` SET `ActionPoiId` = 10629 WHERE `ActionPoiId` = 10139;
UPDATE `gossip_menu_option_action` SET `ActionPoiId` = 10639 WHERE `ActionPoiId` = 10150;
UPDATE `gossip_menu_option_action` SET `ActionPoiId` = 10660 WHERE `ActionPoiId` = 10172;
UPDATE `gossip_menu_option_action` SET `ActionPoiId` = 10649 WHERE `ActionPoiId` = 10160;
UPDATE `gossip_menu_option_action` SET `ActionPoiId` = 10619 WHERE `ActionPoiId` = 10131;
UPDATE `gossip_menu_option_action` SET `ActionPoiId` = 10655 WHERE `ActionPoiId` = 10167;
UPDATE `gossip_menu_option_action` SET `ActionPoiId` = 10656 WHERE `ActionPoiId` = 10168;
UPDATE `gossip_menu_option_action` SET `ActionPoiId` = 10661 WHERE `ActionPoiId` = 10173;
UPDATE `gossip_menu_option_action` SET `ActionPoiId` = 10657 WHERE `ActionPoiId` = 10169;
UPDATE `gossip_menu_option_action` SET `ActionPoiId` = 10635 WHERE `ActionPoiId` = 10145;
UPDATE `gossip_menu_option_action` SET `ActionPoiId` = 10622 WHERE `ActionPoiId` = 10129;
UPDATE `gossip_menu_option_action` SET `ActionPoiId` = 10620 WHERE `ActionPoiId` = 10132;
UPDATE `gossip_menu_option_action` SET `ActionPoiId` = 10638 WHERE `ActionPoiId` = 10149;
UPDATE `gossip_menu_option_action` SET `ActionPoiId` = 10662 WHERE `ActionPoiId` = 10174;
UPDATE `gossip_menu_option_action` SET `ActionPoiId` = 10623 WHERE `ActionPoiId` = 10130;
UPDATE `gossip_menu_option_action` SET `ActionPoiId` = 10650 WHERE `ActionPoiId` = 10162;
UPDATE `gossip_menu_option_action` SET `ActionPoiId` = 10658 WHERE `ActionPoiId` = 10170;
UPDATE `gossip_menu_option_action` SET `ActionPoiId` = 10633 WHERE `ActionPoiId` = 10143;
UPDATE `gossip_menu_option_action` SET `ActionPoiId` = 10659 WHERE `ActionPoiId` = 10171;
UPDATE `gossip_menu_option_action` SET `ActionPoiId` = 10631 WHERE `ActionPoiId` = 10141;
UPDATE `gossip_menu_option_action` SET `ActionPoiId` = 10632 WHERE `ActionPoiId` = 10142;
UPDATE `gossip_menu_option_action` SET `ActionPoiId` = 10625 WHERE `ActionPoiId` = 10135;
UPDATE `gossip_menu_option_action` SET `ActionPoiId` = 10617 WHERE `ActionPoiId` = 10128;
UPDATE `gossip_menu_option_action` SET `ActionPoiId` = 10616 WHERE `ActionPoiId` = 10127;
UPDATE `gossip_menu_option_action` SET `ActionPoiId` = 10663 WHERE `ActionPoiId` = 10175;
UPDATE `gossip_menu_option_action` SET `ActionPoiId` = 2887 WHERE `ActionPoiId` = 10604;
UPDATE `gossip_menu_option_action` SET `ActionPoiId` = 2766 WHERE `ActionPoiId` = 10603;
UPDATE `gossip_menu_option_action` SET `ActionPoiId` = 2714 WHERE `ActionPoiId` = 10552;

DELETE FROM `points_of_interest` WHERE `ID` IN (10533, 10539, 10537, 10019, 10553, 10557, 10543, 10023, 10018, 10562, 10538, 10561, 10559, 10030, 10535, 10607, 10542, 10534, 10020, 10563, 10541, 10570, 10560, 10558, 10544, 10555, 10536, 10556, 10540, 10457, 10554, 10151, 10137, 10144, 10133, 10152, 10147, 10163, 10126, 10153, 10154, 10146, 10155, 10156, 10134, 10164, 10165, 10166, 10157, 10138, 10136, 10148, 10158, 10140, 10159, 10139, 10150, 10172, 10160, 10131, 10167, 10168, 10173, 10169, 10145, 10129, 10132, 10149, 10174, 10130, 10162, 10170, 10143, 10171, 10141, 10142, 10135, 10128, 10127, 10175, 10604, 10603, 10552);


UPDATE `gossip_menu_option_action` SET `ActionPoiId` = 10550 WHERE `ActionPoiId` = 10569;
UPDATE `gossip_menu_option_action` SET `ActionPoiId` = 10123 WHERE `ActionPoiId` = 10125;

DELETE FROM `points_of_interest` WHERE `ID` IN (10569, 10125);

UPDATE `npc_text` SET `VerifiedBuild`=27602 WHERE `ID` IN (23861, 23883, 23973, 24305, 24303, 23804, 23803, 24207, 23796, 23795, 23686, 23598, 23766, 24162, 24163, 24164, 24171, 24181, 24158, 23841, 23843, 23330, 24003, 24420, 25154, 24552, 24506, 24547, 25130, 23555, 23957, 23762, 24118, 23754, 24726, 25732, 21709, 24938, 24912, 24790, 24186, 24261, 24467, 24468, 24954, 25426, 24295, 23905, 23904, 25151, 24076, 24075, 24232, 24737, 24099, 24251, 24717, 24616, 24154, 24070, 24240, 24140, 24476, 24477, 24478, 13584, 24916, 25678, 24441, 24209, 24806, 24599, 25806, 25783, 25069, 6957, 23761, 820, 24541, 24589, 25715, 25528, 25524, 25526, 24953, 24572, 24847, 24513, 23849, 24161, 24198, 24378, 24194, 24326, 23953, 23944, 24190, 23987, 23983, 23986, 24328, 24205, 24124, 23882, 23920, 23783, 23862, 23779, 23829, 24884, 25148, 24275, 23341, 824, 24322, 24672, 24670, 24669, 24204, 24203, 24201, 24664, 24143, 24142, 24417, 24416, 24415, 24103, 24294, 24128, 24129, 24125, 24293, 25434, 25433, 24237, 24269, 24268, 24267, 9051, 24057, 24573, 24025, 24021, 24022, 24002, 25930, 24584, 24926, 24613, 24440, 580, 24369, 25520, 23991, 25121, 24456, 25242, 24458, 24656, 23966, 24296, 24540, 24715, 24714, 25592, 24539, 24337, 25567, 24451, 24355, 24510, 25638, 24188, 24519, 31799, 9727, 25173, 24851, 25273, 25236, 25276, 25275, 25178, 25685, 25248, 24982, 25172, 24983, 25519, 25570, 25174, 14128, 25808, 25801, 25786, 25591, 25609, 24747, 23510, 24930, 6961, 24707, 24705, 23221, 23279, 23509, 7778, 27278, 24993, 24619);
UPDATE `npc_text` SET `VerifiedBuild`=27547 WHERE `ID` IN (24037, 23484, 24026, 24036, 24200, 24926, 23115, 23114, 23214, 24652, 23279, 23510, 23799, 23763, 23275, 23274, 23273, 23272, 24716, 23103, 23105, 23104, 23739, 23259, 23845, 23850, 23932, 23511, 23470, 23564, 24521, 24209, 24993, 24806, 24751, 24747, 24912, 25079, 24725, 24678, 24692, 24180, 24017, 25930, 23221, 24038, 24064, 24063, 24065, 23509, 24056, 22846, 27278, 9478, 22706, 25183, 23877, 25479, 25477, 22665, 25072, 24100, 24135, 23761, 23999, 7778, 25423, 24349, 23878, 24424, 24599, 24440, 9051, 24619, 24172, 24741, 24613, 24531, 24441, 23776, 21709, 13584);
UPDATE `npc_text` SET `VerifiedBuild`=27377 WHERE `ID` IN (20497, 20243, 20496, 20171, 20177, 20173, 20174, 7778, 20119, 20104, 20118, 20213, 21284, 20429, 20112, 20075, 20637, 20769, 20768, 20767, 20766, 20765, 20099, 20098, 20100, 20121, 20955, 22050, 20763, 20703, 19786, 19858, 20636, 19856, 21198, 21197, 21184, 19889, 20163, 20648, 20646, 20643, 19752, 20228, 20649, 19815, 19717, 19955, 20673, 20669, 19966, 19712, 19879, 19881, 19878, 20079, 19635, 19633, 19554, 19555, 19571, 19552, 19556, 19568, 19724, 20017, 19352, 19342, 19876, 20430, 19325, 21026, 21033, 19894, 21631, 14127, 20283, 20097, 20723, 19705, 19697, 19230, 19215, 19217, 19216, 19133, 19227, 19134, 19135, 19180, 21087, 19709, 20203, 20232, 20241, 20240, 21281, 18591, 21701, 14126, 19195, 19047, 19046, 21699, 21698, 19045, 19015, 20101, 21702, 19161, 18832, 18843, 18847, 18834, 20216, 19773, 19772, 19771, 19770, 20932, 20227, 19075, 19078, 19528, 18887, 20016, 19475, 19477, 19478, 18893, 21696, 19394, 19473, 19443, 21282, 21720, 19596, 19595, 19594, 19593, 19592, 19591, 19590, 19589, 19585, 19584, 19185, 19194, 19193, 19192, 19191, 19190, 19189, 19188, 19186, 19187, 19184, 19181, 19376, 19583, 20351, 20361, 20603, 20352, 19404, 20354, 19406, 19405, 19407, 20624, 20344, 20620, 20343, 19466, 19513, 19562, 20618, 19526, 20342, 20622, 20621, 20348, 20350, 22394, 22393, 22376, 18907, 21211, 20306, 20237, 22411, 21627, 20072, 18735, 19766, 19765, 19767, 18667, 18668, 18660, 18659, 21750, 22007, 22014, 21872, 21871, 21809, 19965, 20269, 20276, 20676, 23979, 23714, 23711, 22992, 20335, 14128, 20619, 22338, 22981, 31799, 20330, 20986, 20988, 20987, 20990, 16705, 14783, 20943, 22576, 20947, 20948, 20959, 20589, 20960, 22974, 20970, 20957, 20985, 20989, 22968, 14125, 20949, 20951, 20950, 20993, 21000, 20946, 22539, 21615, 21614, 23008, 23007, 20527, 20528, 20255, 20534, 20533, 20532, 19580, 20524, 20525, 20256, 20519, 20257, 20517, 20515, 20516, 20514, 20511, 20512, 20513, 20259, 20510, 20509, 20258, 20502, 20501, 20260, 20531, 20530, 20529, 20605, 20606, 20607, 20844, 20845, 20843, 20865, 20841, 20840, 20839, 20838, 20837, 20836, 20835, 20834, 20833, 20864, 20832, 20831, 20830, 20829, 20828, 20826, 20823, 20821, 20914, 20917, 20915, 20921, 20916, 20918, 20919, 20912, 20911, 20991, 20910, 20909, 20908, 20862, 20861, 20860, 20859, 20858, 20857, 20856, 20855, 20848, 20854, 20853, 20852, 20851, 20850, 20849, 20846, 20819, 20818, 20816, 20579, 20583, 933, 19719, 21694, 20412, 21285, 20398, 20414, 22648, 22647, 20691, 20413, 20425, 19128, 20067, 20068, 20011, 20696, 20053, 20050, 20052, 21469, 21239, 22373, 22278, 22374, 22365, 20124, 20190, 20189, 20540, 21205, 20012, 20071, 20122, 20937, 19964, 19721, 11714, 21709, 13584, 20697, 23808, 24170, 23823, 24524, 24613, 24306, 5876);
UPDATE `npc_text` SET `VerifiedBuild`=27366 WHERE `ID` IN (19398, 20390, 20388, 20353, 19331, 20278, 19308, 19254, 19345, 18976, 18970, 18895, 19040, 19025, 20384, 18398, 18336, 18337, 18412, 18411, 18405, 18333, 18397, 19367, 19365, 19369, 20685, 20376, 14128, 20681, 20375, 20687, 19889, 18646, 18643, 18644, 19097, 19095, 19077, 19912, 19098, 20727, 19091, 21121, 19094, 19096, 11714, 18789, 18473, 21280);
UPDATE `npc_text` SET `VerifiedBuild`=27356 WHERE `ID` IN (18792, 19332, 18804, 18806, 18805, 18786, 19863, 20183, 18787, 20689, 19277, 7778, 20335, 19293, 19306, 18720, 18453, 18460, 18471, 18450, 18777, 19255, 21624, 21124, 21123, 21092, 21091, 21086, 21085, 21084, 18835, 21619, 21114, 21106, 20696, 7026, 21500, 21501, 21097, 21499, 18838, 538, 8589, 5876);
UPDATE `npc_text` SET `VerifiedBuild`=27144 WHERE `ID` IN (16015, 15756, 15569, 8589);
UPDATE `npc_text` SET `VerifiedBuild`=27101 WHERE `ID` = 17166;
UPDATE `npc_text` SET `VerifiedBuild`=27326 WHERE `ID` IN (17045, 17089, 16986, 16959, 16908, 16923, 17042, 17799, 15104, 16938, 18672, 16847, 16846, 17582, 17518, 17517, 17516, 17534, 17515, 17399, 17472, 17521, 17468, 17533, 17557, 17513, 17467, 17443, 17446, 17401, 17400, 17397, 17740, 17036, 820, 16907, 17055, 17014, 17051, 17013, 17012, 17011, 17010, 17053, 17052, 17105, 17212, 17208, 16906, 17367, 17103, 17104, 21297, 17098, 17228, 17097, 17096, 17099, 16898, 16899, 16872, 16914, 16867, 16767, 17409, 16766, 16903, 17407, 16573, 16406, 16669, 16343, 16262, 21295, 16736, 16825, 16787, 1250, 18221, 18208, 18204, 16839, 16671, 13584, 16635, 16768, 16830, 16728, 16844, 16841, 17491, 16433, 16443, 16366, 16365, 16348, 16777, 16775, 16303, 16259, 16566, 17178, 17177, 16545, 16507, 16508, 16730, 16374, 17170, 16373, 16375, 16376, 16412, 16383, 16544, 18186, 18202, 17559, 17174);
UPDATE `npc_text` SET `VerifiedBuild`=27178 WHERE `ID` IN (16067, 16066, 16064, 16063, 16062, 16061, 16032, 16033, 15783, 17027, 17020, 16015, 17002, 15770, 9546, 15943, 15938);
UPDATE `npc_text` SET `VerifiedBuild`=27843 WHERE `ID` IN (922, 941, 921, 920, 16628, 919, 918, 17200, 31501, 31504, 31505, 16620, 13439, 16621, 16619, 3813, 16630, 16607, 3861, 16606, 3860, 16605, 882, 879, 20025, 901, 906, 10106, 900, 903, 904, 899, 16618, 905, 16617, 902, 898, 13882, 16604, 764, 16603, 16602, 3834, 16601, 18301, 21137, 18000, 933, 5876, 25800, 25797, 25786, 24847, 24513, 6957, 27278);
UPDATE `npc_text` SET `VerifiedBuild`=27791 WHERE `ID` IN (26263, 27101, 26967, 7778, 27278, 24440, 26713, 27070, 6957, 23809, 23740, 24170, 23823, 24252, 23824, 23994, 23808, 24524, 17503, 17496, 17469, 17431, 7727, 17710, 17434, 17432, 17370, 17371, 17360, 17359, 17311, 17310, 17255, 17254, 17253, 17314, 17313, 17259, 17258, 17257, 17315, 17167, 17307, 17308, 17256, 17309, 17312, 17252, 17305, 17192, 17189, 17166, 16868, 16614, 16246, 16202, 16247, 16243, 16172, 16171, 16170, 16169, 16168, 16167, 16166, 16165, 16164, 16105, 16189, 16187, 16186, 16185, 16184, 16183, 16182, 16188, 16239, 16149, 16147, 16069, 16070, 16071, 16019, 16610, 17742, 16014, 16008, 17741, 16270, 16193, 16198, 16194, 16195, 16084, 15880, 15878, 15820, 15819, 15818, 15802, 16122, 16125, 16108, 13584, 17374, 16613, 16203, 9546);

UPDATE `page_text` SET `VerifiedBuild`=27377 WHERE `ID`=4615; -- 4615
UPDATE `page_text` SET `VerifiedBuild`=27377 WHERE `ID`=4614; -- 4614
UPDATE `page_text` SET `VerifiedBuild`=27377 WHERE `ID`=4613; -- 4613
UPDATE `page_text` SET `VerifiedBuild`=27377 WHERE `ID`=4612; -- 4612
UPDATE `page_text` SET `VerifiedBuild`=27377 WHERE `ID`=4611; -- 4611
UPDATE `page_text` SET `VerifiedBuild`=27291 WHERE `ID`=3627; -- 3627
UPDATE `page_text` SET `VerifiedBuild`=27291 WHERE `ID`=3629; -- 3629
UPDATE `page_text` SET `VerifiedBuild`=27291 WHERE `ID`=3626; -- 3626
UPDATE `page_text` SET `VerifiedBuild`=27291 WHERE `ID`=3628; -- 3628
UPDATE `page_text` SET `VerifiedBuild`=27377 WHERE `ID`=4511; -- 4511
UPDATE `page_text` SET `VerifiedBuild`=27843 WHERE `ID`=4899; -- 4899
UPDATE `page_text` SET `VerifiedBuild`=27843 WHERE `ID`=5155; -- 5155
UPDATE `page_text` SET `VerifiedBuild`=27843 WHERE `ID`=5153; -- 5153

UPDATE `gossip_menu` SET `VerifiedBuild`=27602 WHERE (`MenuId`=7896 AND `TextId`=9051); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=27602 WHERE (`MenuId`=16524 AND `TextId`=24003); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=27602 WHERE (`MenuId`=16796 AND `TextId`=24420); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=27602 WHERE (`MenuId`=15145 AND `TextId`=21709); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=27602 WHERE (`MenuId`=9821 AND `TextId`=13584); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=27547 WHERE (`MenuId`=7896 AND `TextId`=9051); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=27547 WHERE (`MenuId`=18757 AND `TextId`=27278); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=27547 WHERE (`MenuId`=16910 AND `TextId`=24613); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=27547 WHERE (`MenuId`=15145 AND `TextId`=21709); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=27547 WHERE (`MenuId`=9821 AND `TextId`=13584); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=27377 WHERE (`MenuId`=6944 AND `TextId`=7778); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=27377 WHERE (`MenuId`=13800 AND `TextId`=19889); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=27366 WHERE (`MenuId`=10188 AND `TextId`=14128); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=27366 WHERE (`MenuId`=8903 AND `TextId`=11714); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=27366 WHERE (`MenuId`=9868 AND `TextId`=11714); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=27366 WHERE (`MenuId`=9821 AND `TextId`=13584); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=27356 WHERE (`MenuId`=6944 AND `TextId`=7778); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=27356 WHERE (`MenuId`=9821 AND `TextId`=13584); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=27356 WHERE (`MenuId`=8522 AND `TextId`=7026); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=27356 WHERE (`MenuId`=13920 AND `TextId`=538); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=27356 WHERE (`MenuId`=14146 AND `TextId`=8589); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=27356 WHERE (`MenuId`=4822 AND `TextId`=5876); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=27144 WHERE (`MenuId`=11520 AND `TextId`=15569); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=27144 WHERE (`MenuId`=14146 AND `TextId`=8589); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=27602 WHERE (`MenuId`=342 AND `TextId`=820); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=27377 WHERE (`MenuId`=10182 AND `TextId`=14127); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=27377 WHERE (`MenuId`=10181 AND `TextId`=14126); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=27326 WHERE (`MenuId`=12480 AND `TextId`=17582); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=27326 WHERE (`MenuId`=12451 AND `TextId`=17515); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=27326 WHERE (`MenuId`=12409 AND `TextId`=17446); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=27326 WHERE (`MenuId`=342 AND `TextId`=820); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=27326 WHERE (`MenuId`=12113 AND `TextId`=17010); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=27326 WHERE (`MenuId`=12138 AND `TextId`=17010); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=27326 WHERE (`MenuId`=12055 AND `TextId`=16898); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=27326 WHERE (`MenuId`=12055 AND `TextId`=16899); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=27326 WHERE (`MenuId`=12062 AND `TextId`=16914); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=27326 WHERE (`MenuId`=11944 AND `TextId`=16767); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=27326 WHERE (`MenuId`=11821 AND `TextId`=16573); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=27326 WHERE (`MenuId`=11722 AND `TextId`=16406); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=27326 WHERE (`MenuId`=11887 AND `TextId`=16669); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=27326 WHERE (`MenuId`=11680 AND `TextId`=16343); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=27326 WHERE (`MenuId`=11641 AND `TextId`=16262); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=27326 WHERE (`MenuId`=11970 AND `TextId`=16787); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=27326 WHERE (`MenuId`=699 AND `TextId`=1250); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=27178 WHERE (`MenuId`=7809 AND `TextId`=9546); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=27843 WHERE (`MenuId`=425 AND `TextId`=922); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=27843 WHERE (`MenuId`=444 AND `TextId`=941); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=27843 WHERE (`MenuId`=424 AND `TextId`=921); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=27843 WHERE (`MenuId`=423 AND `TextId`=920); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=27843 WHERE (`MenuId`=11866 AND `TextId`=16628); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=27843 WHERE (`MenuId`=422 AND `TextId`=919); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=27843 WHERE (`MenuId`=421 AND `TextId`=918); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=27843 WHERE (`MenuId`=20921 AND `TextId`=31501); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=27843 WHERE (`MenuId`=20923 AND `TextId`=31504); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=27843 WHERE (`MenuId`=12243 AND `TextId`=31505); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=27843 WHERE (`MenuId`=11858 AND `TextId`=16620); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=27843 WHERE (`MenuId`=9767 AND `TextId`=13439); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=27843 WHERE (`MenuId`=11859 AND `TextId`=16621); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=27843 WHERE (`MenuId`=11857 AND `TextId`=16619); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=27843 WHERE (`MenuId`=3081 AND `TextId`=3813); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=27843 WHERE (`MenuId`=11867 AND `TextId`=16630); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=27843 WHERE (`MenuId`=11845 AND `TextId`=16607); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=27843 WHERE (`MenuId`=3127 AND `TextId`=3861); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=27843 WHERE (`MenuId`=11844 AND `TextId`=16606); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=27843 WHERE (`MenuId`=3126 AND `TextId`=3860); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=27843 WHERE (`MenuId`=11843 AND `TextId`=16605); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=27843 WHERE (`MenuId`=383 AND `TextId`=882); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=27843 WHERE (`MenuId`=382 AND `TextId`=879); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=27843 WHERE (`MenuId`=13858 AND `TextId`=20025); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=27843 WHERE (`MenuId`=404 AND `TextId`=901); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=27843 WHERE (`MenuId`=409 AND `TextId`=906); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=27843 WHERE (`MenuId`=8164 AND `TextId`=10106); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=27843 WHERE (`MenuId`=403 AND `TextId`=900); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=27843 WHERE (`MenuId`=406 AND `TextId`=903); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=27843 WHERE (`MenuId`=407 AND `TextId`=904); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=27843 WHERE (`MenuId`=402 AND `TextId`=899); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=27843 WHERE (`MenuId`=11856 AND `TextId`=16618); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=27843 WHERE (`MenuId`=408 AND `TextId`=905); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=27843 WHERE (`MenuId`=11855 AND `TextId`=16617); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=27843 WHERE (`MenuId`=405 AND `TextId`=902); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=27843 WHERE (`MenuId`=401 AND `TextId`=898); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=27843 WHERE (`MenuId`=10011 AND `TextId`=13882); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=27843 WHERE (`MenuId`=11842 AND `TextId`=16604); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=27843 WHERE (`MenuId`=265 AND `TextId`=764); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=27843 WHERE (`MenuId`=11841 AND `TextId`=16603); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=27843 WHERE (`MenuId`=11840 AND `TextId`=16602); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=27843 WHERE (`MenuId`=3102 AND `TextId`=3834); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=27843 WHERE (`MenuId`=11839 AND `TextId`=16601); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=27843 WHERE (`MenuId`=13029 AND `TextId`=18301); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=27843 WHERE (`MenuId`=14950 AND `TextId`=21137); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=27843 WHERE (`MenuId`=12803 AND `TextId`=18000); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `TextId`=933); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=27843 WHERE (`MenuId`=4822 AND `TextId`=5876); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=27843 WHERE (`MenuId`=17347 AND `TextId`=25800); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=27843 WHERE (`MenuId`=17348 AND `TextId`=25797); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=27843 WHERE (`MenuId`=17334 AND `TextId`=25786); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=27843 WHERE (`MenuId`=18486 AND `TextId`=26710); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=27843 WHERE (`MenuId`=18536 AND `TextId`=6957); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=27843 WHERE (`MenuId`=18757 AND `TextId`=27278); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=27791 WHERE (`MenuId`=16597 AND `TextId`=7778); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=27791 WHERE (`MenuId`=18757 AND `TextId`=27278); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=27791 WHERE (`MenuId`=16811 AND `TextId`=24440); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=27791 WHERE (`MenuId`=18488 AND `TextId`=26713); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=27791 WHERE (`MenuId`=18486 AND `TextId`=26710); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=27602 WHERE (`MenuId`=6944 AND `TextId`=7778); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=27377 WHERE (`MenuId`=10188 AND `TextId`=14128); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=27377 WHERE (`MenuId`=21043 AND `TextId`=31799); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=27377 WHERE (`MenuId`=10362 AND `TextId`=16705); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=27377 WHERE (`MenuId`=10667 AND `TextId`=14783); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=27377 WHERE (`MenuId`=10183 AND `TextId`=14125); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=27377 WHERE (`MenuId`=9868 AND `TextId`=11714); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=27377 WHERE (`MenuId`=8903 AND `TextId`=11714); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=27377 WHERE (`MenuId`=15145 AND `TextId`=21709); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=27377 WHERE (`MenuId`=9821 AND `TextId`=13584); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=27326 WHERE (`MenuId`=11914 AND `TextId`=16728); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=27326 WHERE (`MenuId`=11889 AND `TextId`=16671); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=27326 WHERE (`MenuId`=9821 AND `TextId`=13584); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=27326 WHERE (`MenuId`=11873 AND `TextId`=16635); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=27326 WHERE (`MenuId`=11872 AND `TextId`=16635); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=27326 WHERE (`MenuId`=11945 AND `TextId`=16768); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=27326 WHERE (`MenuId`=12009 AND `TextId`=16830); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=27326 WHERE (`MenuId`=12018 AND `TextId`=16844); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=27326 WHERE (`MenuId`=12017 AND `TextId`=16841); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=27326 WHERE (`MenuId`=19938 AND `TextId`=29638); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=27326 WHERE (`MenuId`=11739 AND `TextId`=16433); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=27326 WHERE (`MenuId`=11746 AND `TextId`=16443); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=27326 WHERE (`MenuId`=11689 AND `TextId`=16366); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=27326 WHERE (`MenuId`=11688 AND `TextId`=16365); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=27326 WHERE (`MenuId`=11683 AND `TextId`=16348); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=27326 WHERE (`MenuId`=11948 AND `TextId`=16775); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=27326 WHERE (`MenuId`=11949 AND `TextId`=16776); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=27326 WHERE (`MenuId`=11660 AND `TextId`=16303); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=27326 WHERE (`MenuId`=11639 AND `TextId`=16259); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=27326 WHERE (`MenuId`=11813 AND `TextId`=16566); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=27326 WHERE (`MenuId`=11800 AND `TextId`=16545); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=27326 WHERE (`MenuId`=11773 AND `TextId`=16507); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=27326 WHERE (`MenuId`=11774 AND `TextId`=16508); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=27326 WHERE (`MenuId`=11916 AND `TextId`=16730); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=27326 WHERE (`MenuId`=11693 AND `TextId`=16374); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=27326 WHERE (`MenuId`=12227 AND `TextId`=17170); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=27326 WHERE (`MenuId`=11694 AND `TextId`=16375); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=27326 WHERE (`MenuId`=11695 AND `TextId`=16376); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=27326 WHERE (`MenuId`=11725 AND `TextId`=16412); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=27326 WHERE (`MenuId`=11703 AND `TextId`=16383); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=27326 WHERE (`MenuId`=11799 AND `TextId`=16544); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=27291 WHERE (`MenuId`=12224 AND `TextId`=17167); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=27291 WHERE (`MenuId`=12213 AND `TextId`=17166); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=27291 WHERE (`MenuId`=9821 AND `TextId`=13584); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=27291 WHERE (`MenuId`=7809 AND `TextId`=9546); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=27602 WHERE (`MenuId`=347 AND `TextId`=824); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=27602 WHERE (`MenuId`=7481 AND `TextId`=9051); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=27602 WHERE (`MenuId`=17989 AND `TextId`=25930); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=27602 WHERE (`MenuId`=17533 AND `TextId`=24926); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=27602 WHERE (`MenuId`=16910 AND `TextId`=24613); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=27602 WHERE (`MenuId`=83 AND `TextId`=580); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=27602 WHERE (`MenuId`=21043 AND `TextId`=31799); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=27602 WHERE (`MenuId`=7928 AND `TextId`=9727); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=27602 WHERE (`MenuId`=10188 AND `TextId`=14128); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=27602 WHERE (`MenuId`=5665 AND `TextId`=6961); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=27602 WHERE (`MenuId`=18757 AND `TextId`=27278); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=27377 WHERE (`MenuId`=4822 AND `TextId`=5876); -- 0
UPDATE `gossip_menu_option` SET `VerifiedBuild`=27602 WHERE (`MenuId`=7896 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=27602 WHERE (`MenuId`=16524 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=27602 WHERE (`MenuId`=9821 AND `OptionIndex`=3);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=27602 WHERE (`MenuId`=9821 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=27602 WHERE (`MenuId`=9821 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=27547 WHERE (`MenuId`=9821 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=27547 WHERE (`MenuId`=7896 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=27547 WHERE (`MenuId`=18757 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=27547 WHERE (`MenuId`=9821 AND `OptionIndex`=3);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=27377 WHERE (`MenuId`=6944 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=27366 WHERE (`MenuId`=10188 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=27366 WHERE (`MenuId`=8903 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=27366 WHERE (`MenuId`=9868 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=27366 WHERE (`MenuId`=9821 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=27366 WHERE (`MenuId`=9821 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=27356 WHERE (`MenuId`=6944 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=27356 WHERE (`MenuId`=9821 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=27356 WHERE (`MenuId`=9821 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=27356 WHERE (`MenuId`=8522 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=27356 WHERE (`MenuId`=13920 AND `OptionIndex`=9);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=27356 WHERE (`MenuId`=13920 AND `OptionIndex`=8);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=27356 WHERE (`MenuId`=14146 AND `OptionIndex`=9);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=27356 WHERE (`MenuId`=14146 AND `OptionIndex`=8);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=27356 WHERE (`MenuId`=4822 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=27144 WHERE (`MenuId`=11520 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=27144 WHERE (`MenuId`=14146 AND `OptionIndex`=9);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=27144 WHERE (`MenuId`=14146 AND `OptionIndex`=8);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=27602 WHERE (`MenuId`=342 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=27602 WHERE (`MenuId`=342 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=27377 WHERE (`MenuId`=10182 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=27377 WHERE (`MenuId`=10181 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=27326 WHERE (`MenuId`=342 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=27326 WHERE (`MenuId`=11821 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=27326 WHERE (`MenuId`=699 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=27843 WHERE (`MenuId`=421 AND `OptionIndex`=14);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=27843 WHERE (`MenuId`=421 AND `OptionIndex`=8);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=27843 WHERE (`MenuId`=421 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=27843 WHERE (`MenuId`=12243 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=27843 WHERE (`MenuId`=11845 AND `OptionIndex`=5);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=27843 WHERE (`MenuId`=11845 AND `OptionIndex`=4);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=27843 WHERE (`MenuId`=11845 AND `OptionIndex`=3);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=27843 WHERE (`MenuId`=11845 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=27843 WHERE (`MenuId`=11845 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=27843 WHERE (`MenuId`=11843 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=27843 WHERE (`MenuId`=11843 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=27843 WHERE (`MenuId`=11855 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=27843 WHERE (`MenuId`=11855 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=27843 WHERE (`MenuId`=11841 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=27843 WHERE (`MenuId`=11841 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=27843 WHERE (`MenuId`=11839 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=27843 WHERE (`MenuId`=11839 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=16);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=12);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=3);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=27843 WHERE (`MenuId`=435 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=27843 WHERE (`MenuId`=4822 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=27843 WHERE (`MenuId`=17348 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=27843 WHERE (`MenuId`=17348 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=27843 WHERE (`MenuId`=17348 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=27843 WHERE (`MenuId`=17334 AND `OptionIndex`=11);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=27843 WHERE (`MenuId`=17334 AND `OptionIndex`=10);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=27843 WHERE (`MenuId`=17334 AND `OptionIndex`=9);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=27843 WHERE (`MenuId`=17334 AND `OptionIndex`=8);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=27843 WHERE (`MenuId`=17334 AND `OptionIndex`=7);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=27843 WHERE (`MenuId`=17334 AND `OptionIndex`=6);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=27843 WHERE (`MenuId`=17334 AND `OptionIndex`=5);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=27843 WHERE (`MenuId`=17334 AND `OptionIndex`=4);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=27843 WHERE (`MenuId`=17334 AND `OptionIndex`=3);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=27843 WHERE (`MenuId`=17334 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=27843 WHERE (`MenuId`=17334 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=27843 WHERE (`MenuId`=17334 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=27843 WHERE (`MenuId`=18486 AND `OptionIndex`=4);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=27843 WHERE (`MenuId`=18486 AND `OptionIndex`=3);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=27843 WHERE (`MenuId`=18486 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=27843 WHERE (`MenuId`=18536 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=27843 WHERE (`MenuId`=18757 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=27791 WHERE (`MenuId`=16597 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=27791 WHERE (`MenuId`=18757 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=27791 WHERE (`MenuId`=16811 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=27791 WHERE (`MenuId`=18488 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=27602 WHERE (`MenuId`=6944 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=27377 WHERE (`MenuId`=10188 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=27377 WHERE (`MenuId`=21043 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=27377 WHERE (`MenuId`=10362 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=27377 WHERE (`MenuId`=10183 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=27377 WHERE (`MenuId`=9868 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=27377 WHERE (`MenuId`=9868 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=27377 WHERE (`MenuId`=9821 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=27377 WHERE (`MenuId`=8903 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=27377 WHERE (`MenuId`=9821 AND `OptionIndex`=3);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=27377 WHERE (`MenuId`=9821 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=27326 WHERE (`MenuId`=9821 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=27326 WHERE (`MenuId`=9821 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=27291 WHERE (`MenuId`=12213 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=27291 WHERE (`MenuId`=11538 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=27291 WHERE (`MenuId`=9821 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=27291 WHERE (`MenuId`=9821 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=27602 WHERE (`MenuId`=347 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=27602 WHERE (`MenuId`=7481 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=27602 WHERE (`MenuId`=17533 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=27602 WHERE (`MenuId`=83 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=27602 WHERE (`MenuId`=4824 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=27602 WHERE (`MenuId`=21043 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=27602 WHERE (`MenuId`=21043 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=27602 WHERE (`MenuId`=10188 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=27602 WHERE (`MenuId`=5665 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=27602 WHERE (`MenuId`=18757 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=27377 WHERE (`MenuId`=4822 AND `OptionIndex`=0);
