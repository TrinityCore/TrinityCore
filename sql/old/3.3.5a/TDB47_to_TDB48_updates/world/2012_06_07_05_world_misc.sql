-- Remove some bad spawns in world
DELETE FROM `creature` WHERE `guid` IN (45208,45099,45075,45136,12925,12402);
DELETE FROM `creature_addon` WHERE `guid` IN (45208,45099,45075,45136,12925,12402);

-- Some missing Gossip
UPDATE `creature_template` SET `gossip_menu_id`=9054 WHERE `entry`=25021;
UPDATE `creature_template` SET `gossip_menu_id`=9056 WHERE `entry`=25022;
UPDATE `creature_template` SET `gossip_menu_id`=9057 WHERE `entry`=25023;
UPDATE `creature_template` SET `gossip_menu_id`=9054 WHERE `entry`=25024;
UPDATE `creature_template` SET `gossip_menu_id`=9077 WHERE `entry`=25025;
DELETE FROM `gossip_menu` WHERE `entry`=9054 AND `text_id`=12243;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (9054,12243);
DELETE FROM `gossip_menu` WHERE `entry`=9057 AND `text_id`=12245;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (9057,12245);
DELETE FROM `gossip_menu` WHERE `entry`=9077 AND `text_id`=12275;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (9077,12275);

-- Zeppelin: <The Thundercaller> "Durotar to Tirisfal Glades"
DELETE FROM `creature_transport` WHERE `transport_entry`=164871;
INSERT INTO `creature_transport` (`guid`,`transport_entry`,`npc_entry`,`TransOffsetX`,`TransOffsetY`,`TransOffsetZ`,`TransOffsetO`,`emote`) VALUES
(1,164871,15214,7.005304,-7.647912,-16.11262,2.897247,0), -- Invisible Stalker
(2,164871,24934,-4.516505,-13.11248,-22.59472,1.53589,0), -- Snack-O-Matic IV
(3,164871,24935,-6.37827,-13.18376,-22.59391,4.712389,0), -- Vend-O-Tron D-Luxe
(4,164871,25070,-9.407872,-8.023982,-17.15783,3.176499,0), -- Chief Officer Coppernut <The Thundercaller>
(5,164871,25071,7.248865,-5.480326,-17.68592,4.817109,432), -- Crewman Rusthammer <The Thundercaller>
(6,164871,25072,8.008065,-10.71344,-17.67366,1.169371,432), -- Crewman Quickfix <The Thundercaller>
(7,164871,25074,5.023749,-7.69781,-17.78876,5.986479,432), -- Crewman Sparkfly <The Thundercaller>
(8,164871,25075,-8.875813,-11.40282,-22.5883,6.248279,0), -- Zeppelin Controls
(9,164871,25075,-3.307774,-9.474165,-23.69589,1.553343,0), -- Zeppelin Controls
(10,164871,25075,4.482075,-13.40077,-23.59003,1.623156,0), -- Zeppelin Controls
(11,164871,25075,-3.314179,-6.128806,-23.69835,4.677482,0), -- Zeppelin Controls
(12,164871,25075,4.362147,-2.254167,-23.59002,4.712389,0), -- Zeppelin Controls
(13,164871,25075,-4.161887,-7.687522,-23.69754,0,0), -- Zeppelin Controls
(14,164871,25075,11.74357,-10.44521,-24.21887,6.161012,0), -- Zeppelin Controls
(15,164871,25075,10.82609,-12.18536,-23.48949,3.176499,0), -- Zeppelin Controls
(16,164871,25075,10.70341,-3.505423,-23.49001,3.246312,0), -- Zeppelin Controls
(17,164871,25076,-2.727229,-7.772857,-23.69677,1.553343,432), -- Navigator Fairweather <The Thundercaller>
(18,164871,25077,-19.68856,-8.170582,-14.37648,3.176499,0), -- Sky-Captain Cloudkicker <The Thundercaller>
(19,164871,25079,-5.1094,-11.14663,-17.60601,4.485496,0), -- Deathguard Fowles <The Thundercaller>
(20,164871,25083,-5.212496,-4.927022,-17.5966,1.43117,0), -- Deathguard Lawson <The Thundercaller>
(21,164871,25171,-8.703286,-11.40788,-22.58871,0.03490658,0); -- Invisible Stalker (Scale x0.5)
-- gameobject 21680 -6.905273,-4.876801,-17.51628,5.911792 Rotation: 0,0,0.9850225,0.1724255

-- Zeppelin: <The Zephyr> "Durotar to Thunder Bluff"
DELETE FROM `creature_transport` WHERE `transport_entry`=190549;
INSERT INTO `creature_transport` (`guid`,`transport_entry`,`npc_entry`,`TransOffsetX`,`TransOffsetY`,`TransOffsetZ`,`TransOffsetO`,`emote`) VALUES
(1,190549,3084,-4.83257,-4.312334,-17.63218,1.623156,0), -- Bluffwatcher
(2,190549,3084,-5.206744,-11.34318,-17.61012,4.712389,0), -- Bluffwatcher
(3,190549,24934,10.32099,-3.573514,-23.49413,3.176499,0), -- Snack-O-Matic IV
(4,190549,24935,10.2871,-12.02722,-23.49424,3.106686,0), -- Vend-O-Tron D-Luxe
(5,190549,25075,-3.396398,-7.905448,-23.69672,6.248279,0), -- Zeppelin Controls
(6,190549,34715,-9.183155,-7.775729,-17.21699,3.281219,0), -- Sky-Captain "Dusty" Blastnut <The Zephyr>
(7,190549,34717,-13.67017,-12.40177,-15.98756,4.590216,0), -- Crewman Pipewrench <The Zephyr>
(8,190549,34718,13.74505,-5.128461,-24.04518,0.1396263,207), -- Crewman Deadbolt <The Zephyr>
(9,190549,34719,7.623085,-5.025319,-17.67015,4.921828,28), -- Crewman Grit <The Zephyr>
(10,190549,34721,-0.919197,-6.164221,-23.67286,3.577925,0), -- Chief Officer Ograh <The Zephyr>
(11,190549,34723,-17.47968,-5.606984,-14.92807,3.228859,0), -- Watcher Tolwe <The Zephyr>
(12,190549,34730,-2.166869,-7.854215,-23.6919,3.385939,0); -- Navigator Zippik <The Zephyr>

-- Zeppelin: <The Iron Eagle> "Durotar to Stranglethorn Val"
DELETE FROM `creature_transport` WHERE `transport_entry`=175080;
INSERT INTO `creature_transport` (`guid`,`transport_entry`,`npc_entry`,`TransOffsetX`,`TransOffsetY`,`TransOffsetZ`,`TransOffsetO`,`emote`) VALUES
(1,175080,24924,-1.207598,-9.948863,-23.67485,0.1570796,0), -- Sky-Captain Bomblast <The Iron Eagle>
(2,175080,24926,-10.3057,-12.10524,-16.96907,5.927236,0), -- Chief Officer Brassbolt <The Iron Eagle> <PATHING>
(3,175080,24927,-1.874165,-7.847112,-23.68718,3.385939,0), -- Navigator Sparksizzle <The Iron Eagle>
(4,175080,24929,9.083008,-4.964111,-23.59211,1.594056,0), -- Crewman Crosswire <The Iron Eagle>
(5,175080,24930,-17.0083,-7.874878,-15.18782,3.141593,0), -- Crewman Gazzlegear <The Iron Eagle>
(6,175080,24931,7.884921,-11.15133,-17.76227,4.90483,432), --  Crewman Fastwrench <The Iron Eagle> <PATHING>
(7,175080,24934,9.209188,-3.503923,-23.51212,3.124139,0), -- Snack-O-Matic IV
(8,175080,24935,9.554915,-12.02288,-23.50588,3.124139,0), -- Vend-O-Tron D-Luxe
(9,175080,25075,-2.705565,-7.845885,-23.6967,0.03490658,0), -- Zeppelin Controls
(10,175080,25080,-4.910018,-4.742365,-17.61534,1.605703,0), -- Grunt Umgor
(11,175080,25081,-4.939394,-10.80493,-17.61089,4.712389,0); -- Grunt Ounda

-- Zeppelin: <The Mighty Wind> "Durotar to Borean Tundra"
DELETE FROM `creature_transport` WHERE `transport_entry`=186238;
INSERT INTO `creature_transport` (`guid`,`transport_entry`,`npc_entry`,`TransOffsetX`,`TransOffsetY`,`TransOffsetZ`,`TransOffsetO`,`emote`) VALUES
(1,186238,25075,9.44542,-7.849475,-16.60061,0.05235988,0), -- Zeppelin Controls
(2,186238,31720,-16.56853,-5.083331,-15.94212,1.989675,0), -- Crewman Shubbscoop <The Mighty Wind>
(3,186238,31723,-10.75516,-12.81286,-16.77452,4.537856,0), -- Crewman Barrowswizzle <The Mighty Wind>
(4,186238,31724,5.77627,-2.004689,-17.72185,1.64061,0), -- Crewman Paltertop <The Mighty Wind>
(5,186238,31725,10.69841,-7.821921,-16.60061,3.281219,0), -- Sky-Captain LaFontaine <The Mighty Wind>
(6,186238,31726,-3.453068,-13.78959,-17.61107,1.43117,0), -- Grunt Gritch
(7,186238,31727,-3.383076,-1.913925,-17.6198,4.729842,0); -- Grunt Grikee

-- Ship: <Northspear> "Wetlands to Howling Fjord"
DELETE FROM `creature_transport` WHERE `transport_entry`=181688;
INSERT INTO `creature_transport` (`guid`,`transport_entry`,`npc_entry`,`TransOffsetX`,`TransOffsetY`,`TransOffsetZ`,`TransOffsetO`,`emote`) VALUES
(1,181688,31759,-9.170654,-9.222412,9.44523,4.339638,0), -- Sailor Jansen <Northspear>
(2,181688,31760,-24.34204,-1.495605,11.79066,4.531185,0), -- Sailor Berg <Northspear>
(3,181688,31761,17.25,3.982666,9.827404,1.127068,0), -- Sailor Davies <Northspear>
(4,181688,31762,34.08345,-0.002845,19.79711,3.124139,0), -- Navigator Marcus <Northspear>
(5,181688,31763,30.11512,-5.088479,19.32816,3.089233,0), -- Captain John Brookman <Northspear>
(6,181688,31764,26.07068,2.057755,19.32802,3.001966,0); -- First Mate Kacy Dishon <Northspear>

-- Ship: <The Kraken> "Stormwind to Borean Tundra"
DELETE FROM `creature_transport` WHERE `transport_entry`=190536;
INSERT INTO `creature_transport` (`guid`,`transport_entry`,`npc_entry`,`TransOffsetX`,`TransOffsetY`,`TransOffsetZ`,`TransOffsetO`,`emote`) VALUES
(1,190536,31788,27.59511,-2.344238,19.32811,3.228859,0), -- Captain Constance <The Kraken>
(2,190536,31789,28.09979,5.993899,19.32799,3.647738,0), -- First Mate Fitzgerald <The Kraken>
(3,190536,31790,34.22358,0.067648,19.76266,3.071779,0), -- Navigator Meyer <The Kraken>
(4,190536,31791,0.919363,8.75723,9.436611,1.256637,0), -- Sailor Dawning <The Kraken>
(5,190536,31792,-4.766113,0.09985352,9.36669,4.834562,0), -- Sailor Picardo <The Kraken>
(6,190536,31793,17.146,-3.921387,9.813052,5.497081,0); -- Sailor Phillips <The Kraken>

-- Ship: <Feathermoon Ferry> "Feralas to Feathermoon Stronghold"
DELETE FROM `creature_transport` WHERE `transport_entry`=177233;
INSERT INTO `creature_transport` (`guid`,`transport_entry`,`npc_entry`,`TransOffsetX`,`TransOffsetY`,`TransOffsetZ`,`TransOffsetO`,`emote`) VALUES
(1,177233,3681,-38.64771,-0.071194,6.08577,0.06981317,0), -- Wisp
(2,177233,3681,29.56227,0.119925,24.45391,0.08726646,0), -- Wisp
(3,177233,25019,12.80499,-7.601957,6.105068,2.9147,0), -- Merchant Felagunne <Feathermoon Ferry>
(4,177233,25020,12.95386,7.333937,6.131125,3.281219,0), -- Galley Chief Alunwea <Feathermoon Ferry>
(5,177233,25021,-21.41735,-2.833596,4.391686,6.248279,0), -- Mariner Moonblade <Feathermoon Ferry>
(6,177233,25022,20.86332,-1.285908,11.80898,2.949606,0), -- Mariner Stillwake <Feathermoon Ferry>
(7,177233,25023,-36.76907,0.169367,5.975922,3.176499,0), -- Mariner Everwatch <Feathermoon Ferry>
(8,177233,25024,-21.65951,3.22012,4.402726,0.1396263,0), -- Mariner Softsong <Feathermoon Ferry>
(9,177233,25025,31.13095,-0.454317,16.73282,2.96706,0); -- Captain Idrilae <Feathermoon Ferry>
